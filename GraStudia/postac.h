#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#pragma once 

class Postac //klasa posiadajaca wirtualna metode nazywamy klasa abstrakcyjna
{
	public:
		int zycie;
		virtual void RysujSpritea(sf::RenderWindow& window) = 0;//czysto wirtualna metoda
};

