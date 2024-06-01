#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "postac.h"

class Gracz: public Postac
{
public:
	float predkosc = 100.f;
	sf::CircleShape cialo;
	sf::Texture tekstura;
	sf::Sprite SpriteGracza;
	Gracz(const std::string& texturePath, float x, float y, float szybkosc);
	void RuchPostaci(sf::Vector2f delta);
	virtual void RysujSpritea(sf::RenderWindow& window);
	void Aktualizacja(const sf::Time& dt);
	sf::Vector2f getPosition() const;
};

