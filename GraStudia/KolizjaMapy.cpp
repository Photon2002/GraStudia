#include "KolizjaMapy.h"
#include <SFML/Graphics.hpp>

void KolizjaMapy::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    {
        states.transform *= getTransform();

        states.texture = nullptr;

        // Rysowanie tablicy wierzcho�k�w
        for (std::size_t i = 0; i < m_vertices.getVertexCount(); i += 6) {
            // Sprawdzenie, czy kafelk ma kolizj�
            if (m_vertices[i].color == sf::Color::Red) {
                // Rysowanie dw�ch tr�jk�t�w reprezentuj�cych kolizj�
                target.draw(&m_vertices[i], 6, sf::Triangles, states);
            }
        }
    }
}

bool KolizjaMapy::kolizja(sf::Vector2u tileSize, std::vector<int> collisionData, unsigned int width, unsigned int height)
{
    // Zmiana rozmiaru tablicy wierzcho�k�w, aby pomie�ci� wszystkie kafelki planszy
    m_vertices.setPrimitiveType(sf::Triangles);
    m_vertices.resize(width * height * 6);

    // Iteracja po wszystkich kafelkach planszy
    for (unsigned int i = 0; i < width; ++i)
    {
        for (unsigned int j = 0; j < height; ++j)
        {
            // Pobranie warto�ci kolizji dla bie��cego kafelka
            int hasCollision = collisionData[i + j * width];

            // Pobranie wska�nika do wierzcho�k�w tr�jk�t�w bie��cego kafelka
            sf::Vertex* triangles = &m_vertices[(i + j * width) * 6];

            // Je�li kafelek ma kolizj�, rysujemy go
            if (hasCollision == 1)
            {
                sf::Vector2f rectPosition(i * tileSize.x, j * tileSize.y);
                sf::Vector2f rectSize(tileSize.x, tileSize.y);

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