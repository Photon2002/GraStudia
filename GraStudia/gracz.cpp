#include "gracz.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


/*Postac::Postac(float radius) {
    cialo.setRadius(radius);
    cialo.setFillColor(sf::Color::Blue);
    cialo.setPosition(100, 100);  // Ustawienie pocz¹tkowej pozycji
    cialo.setOrigin(radius, radius);  // Ustawienie œrodka ko³a
}

void Postac::draw(sf::RenderWindow& window) {
    window.draw(cialo);
}
*/
Gracz::Gracz(const std::string& texturePath, float x, float y, float szybkosc)
{
    if (!tekstura.loadFromFile("assets/gracz.png", sf::IntRect(39, 6, 19, 25)))
    {
        perror("Blad tekstury!");
    }
    SpriteGracza.setTexture(tekstura);
    SpriteGracza.setPosition(x, y);
}

void Gracz::RuchPostaci(sf::Vector2f delta)
{
    SpriteGracza.move(delta);
}

void Gracz::RysujSpritea(sf::RenderWindow& window)
{
    window.draw(SpriteGracza);
}

void Gracz::Aktualizacja(const sf::Time& dt)
{
    sf::Vector2f poruszanie(0.f, 0.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        poruszanie.y -= predkosc * dt.asSeconds();
        tekstura.loadFromFile("assets/gracz.png", sf::IntRect(39, 102, 19, 25));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        poruszanie.y += predkosc * dt.asSeconds();
        tekstura.loadFromFile("assets/gracz.png", sf::IntRect(39, 6, 19, 25));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        poruszanie.x -= predkosc * dt.asSeconds();
        tekstura.loadFromFile("assets/gracz.png", sf::IntRect(39, 38, 19, 25));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        poruszanie.x += predkosc * dt.asSeconds();
        tekstura.loadFromFile("assets/gracz.png", sf::IntRect(39, 70, 19, 25));
    }
    RuchPostaci(poruszanie);
}

sf::Vector2f Gracz::getPosition() const
{
    return SpriteGracza.getPosition(); // Zak³adam, ¿e masz sprite reprezentuj¹cy gracza
}
