#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "gracz.h"

class Gracz;

class Pocisk
{
	friend class gracz;

	private:
		sf::Texture TeksturaPocisku;
		float predkoscPocisku = 300.f;
		float zasieg = 150.f;
		float promien = 5.0f;
		Gracz::Kierunek kierunekLotu = Gracz::Kierunek::W_DOL;
		bool czyKopia = false;

	public:
		sf::Vector2f PozycjaPocisku;
		sf::CircleShape KolizjaPocisku;
		sf::Sprite SpritePocisku;
		Pocisk(const std::string& texturePath, const Gracz& gracz, float szybkosc);
		Pocisk(const Pocisk& pocisk); // Konstruktor kopiuj¹cy
		~Pocisk();
		void RysujPocisk(sf::RenderWindow& window);
		void AktualizujPozycje(const Gracz& gracz);
		bool czyPozaZasiegiem(const Gracz& gracz) const;
		void Strzal(sf::RenderWindow& window, std::vector<Pocisk>& pociski, const Gracz& gracz);
		void LotPocisku(const sf::Time& dt);
		//void LotPocisku(const sf::Time& dt, const Gracz& gracz);
};

	