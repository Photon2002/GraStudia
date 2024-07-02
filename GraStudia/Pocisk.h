#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Gracz;

class Pocisk
{
	friend class gracz;

	private:
		sf::Texture TeksturaPocisku;
		float predkoscPocisku = 300.f;
		float zasieg = 200.f;
		float promien = 5.0f;
		bool czyKopia = false;

	public:
		sf::Vector2f PozycjaPocisku;
		sf::CircleShape KolizjaPocisku;
		sf::Sprite SpritePocisku;
		Pocisk(const std::string& texturePath, const Gracz& gracz, float szybkosc);
		Pocisk(const Pocisk& pocisk); // Konstruktor kopiuj�cy
		~Pocisk();
		void RysujPocisk(sf::RenderWindow& window);
		void AktualizujPozycje(const Gracz& gracz);
		bool czyPozaZasiegiem(const Gracz& gracz) const;
		void Strzal(sf::RenderWindow& window, std::vector<Pocisk>& pociski);
		//void LotPocisku(const sf::Time& dt);
		void LotPocisku(const sf::Time& dt, const Gracz& gracz);
};

