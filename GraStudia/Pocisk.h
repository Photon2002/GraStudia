#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Gracz;

class Pocisk
{
	friend class gracz;

	private:
		sf::Vector2f PozycjaPocisku;
		sf::Texture TeksturaPocisku;
		float predkosc = 300.f;
		float zasieg = 100.f;
		float promien = 5.0f;
	public:
		sf::CircleShape KolizjaPocisku;
		sf::Sprite SpritePocisku;
		Pocisk(const std::string& texturePath, const Gracz& gracz, float szybkosc);
		Pocisk(const Pocisk& pocisk); // Konstruktor kopiuj¹cy
		~Pocisk();
		void RysujPocisk(sf::RenderWindow& window);
		void AktualizujPozycje(const Gracz& gracz);
};

