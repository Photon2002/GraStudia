#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "postac.h"

class Pocisk;

class Gracz: public Postac
{
	private:
		sf::Vector2f poprzedniaPozycjaGracza;
		sf::Texture tekstura;
		float predkosc = 100.f;
		void RuchPostaci(sf::Vector2f delta);
		
	public:
		sf::Sprite SpriteGracza;
		enum Kierunek {
			W_GORE,
			W_DOL,
			W_LEWO,
			W_PRAWO
		};
		Kierunek kierunek_postaci = W_DOL;
		sf::RectangleShape KolizjaGracza;
		Gracz(const std::string& texturePath, float x, float y, float szybkosc);
		virtual void RysujSpritea(sf::RenderWindow& window);
		void Aktualizacja(const sf::Time& dt);
		sf::Vector2f getPosition() const;
		sf::Vector2f getPoprzedniaPozycjaGracza() const;
		void setPoprzedniaPozycjaGracza(const sf::Vector2f& pozycja);

};

