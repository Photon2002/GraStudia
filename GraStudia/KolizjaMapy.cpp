#include "KolizjaMapy.h"
#include <SFML/Graphics.hpp>

void KolizjaMapy::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    {
        // apply the transform
        states.transform *= getTransform();

        // apply the tileset texture
        states.texture = nullptr;

        // Rysowanie tablicy wierzcho³ków
        //target.draw(m_vertices, states);
        for (std::size_t i = 0; i < m_vertices.getVertexCount(); i += 6) {
            // Sprawdzenie, czy kafelk ma kolizjê
            if (m_vertices[i].color == sf::Color::Red) {
                // Rysowanie dwóch trójk¹tów reprezentuj¹cych kolizjê
                target.draw(&m_vertices[i], 6, sf::Triangles, states);
            }
        }
    }
}

bool KolizjaMapy::kolizja(sf::Vector2u tileSize, std::vector<int> collisionData, unsigned int width, unsigned int height)
{

    // Zmiana rozmiaru tablicy wierzcho³ków, aby pomieœciæ wszystkie kafelki planszy
    m_vertices.setPrimitiveType(sf::Triangles);
    m_vertices.resize(width * height * 6);

    // Iteracja po wszystkich kafelkach planszy
    for (unsigned int i = 0; i < width; ++i)
    {
        for (unsigned int j = 0; j < height; ++j)
        {
            // Pobranie wartoœci kolizji dla bie¿¹cego kafelka
            int hasCollision = collisionData[i + j * width];

            // Pobranie wskaŸnika do wierzcho³ków trójk¹tów bie¿¹cego kafelka
            sf::Vertex* triangles = &m_vertices[(i + j * width) * 6];

            // Jeœli kafelek ma kolizjê, rysujemy go
            if (hasCollision == 1)
            {
                // Definicja wspó³rzêdnych wierzcho³ków kafelka (kolizji)
                /*triangles[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
                triangles[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
                triangles[2].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);
                triangles[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);
                triangles[4].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
                triangles[5].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);

                // Ustawienie koloru kolizji na czerwony
                for (int k = 0; k < 6; ++k)
                {
                    triangles[k].color = sf::Color::Red;
                }
                sf::ConvexShape collisionShape;
                collisionShape.setPointCount(6);
                for (int k = 0; k < 6; ++k)
                {
                    collisionShape.setPoint(k, triangles[k].position);
                }
                collisionShape.setFillColor(sf::Color::Transparent);
                collisionShape.setOutlineThickness(1.f);
                collisionShape.setOutlineColor(sf::Color::Green);

                ListaObiektowKolizyjnych.push_back(collisionShape);*/
                sf::Vector2f rectPosition(i * tileSize.x, j * tileSize.y);
                sf::Vector2f rectSize(tileSize.x, tileSize.y);

                // Tworzymy RectangleShape
                sf::RectangleShape collisionRect(rectSize);
                collisionRect.setPosition(rectPosition);
                collisionRect.setFillColor(sf::Color::Transparent);
                collisionRect.setOutlineThickness(1.f);
                collisionRect.setOutlineColor(sf::Color::Green);

                ListaObiektowKolizyjnych.push_back(collisionRect);

            }
        }
    }

    return true;
}