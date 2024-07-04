#include "gracz.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

Gracz::Gracz(const std::string& texturePath, float x, float y, float szybkosc)
{
    if (!tekstura.loadFromFile("assets/gracz.png", sf::IntRect(39, 6, 19, 25)))
    {
        throw std::exception("Nie mozna zaladowac tekstury!");
    }
    SpriteGracza.setTexture(tekstura);
    SpriteGracza.setPosition(x, y);
    KolizjaGracza.setSize(sf::Vector2f(SpriteGracza.getGlobalBounds().width, SpriteGracza.getGlobalBounds().height));
    KolizjaGracza.setPosition(x, y);
    KolizjaGracza.setFillColor(sf::Color::Green);
}

void Gracz::RuchPostaci(sf::Vector2f delta)
{
    poprzedniaPozycjaGracza = KolizjaGracza.getPosition();
    SpriteGracza.move(delta);
    KolizjaGracza.move(delta);
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
        kierunek_postaci = W_GORE;
        poruszanie.y -= predkosc * dt.asSeconds();
        tekstura.loadFromFile("assets/gracz.png", sf::IntRect(39, 102, 19, 25));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        kierunek_postaci = W_DOL;
        poruszanie.y += predkosc * dt.asSeconds();
        tekstura.loadFromFile("assets/gracz.png", sf::IntRect(39, 6, 19, 25));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        kierunek_postaci = W_LEWO;
        poruszanie.x -= predkosc * dt.asSeconds();
        tekstura.loadFromFile("assets/gracz.png", sf::IntRect(39, 38, 19, 25));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        kierunek_postaci = W_PRAWO;
        poruszanie.x += predkosc * dt.asSeconds();
        tekstura.loadFromFile("assets/gracz.png", sf::IntRect(39, 70, 19, 25));
    }
    RuchPostaci(poruszanie);
}


sf::Vector2f Gracz::getPosition() const
{
    return SpriteGracza.getPosition();
}

sf::Vector2f Gracz::getPoprzedniaPozycjaGracza() const
{
    return poprzedniaPozycjaGracza;
}

void Gracz::setPoprzedniaPozycjaGracza(const sf::Vector2f& pozycja)
{
    poprzedniaPozycjaGracza = pozycja;
}
