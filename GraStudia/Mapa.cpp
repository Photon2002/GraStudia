#include <SFML/Graphics.hpp>
#include <iostream>
#include "Mapa.h"

Mapa::Mapa(const std::string& sciezkaPliku)
{
	if (!mapa.loadFromFile(sciezkaPliku))
	{
		std::cerr << "Blad wczytywania pliku, nie mozna wczytac mapy!" << std::endl;
		exit(EXIT_FAILURE);
	}
	sf::Vector2u rozmiar = mapa.getSize();
	szerokosc = rozmiar.x;
	wysokosc = rozmiar.y;
	TablicaWartosci.resize(szerokosc, std::vector<int>(wysokosc, 0));

	WczytajMape();
}


void Mapa::WczytajMape()
{
	for (unsigned int y = 0; y < wysokosc; y++)
	{
		for (unsigned int x = 0; x < szerokosc; x++)
		{
			sf::Color KolorPixela = mapa.getPixel(x, y);

			if(KolorPixela.r == 0 && KolorPixela.g == 0 && KolorPixela.b == 255) {
				TablicaWartosci[y][x] = 0;
			}
			else if (KolorPixela.r == 0 && KolorPixela.g == 255 && KolorPixela.b == 0) {
				TablicaWartosci[y][x] = 1;
			}
			else if (KolorPixela.r == 86 && KolorPixela.g == 47 && KolorPixela.b == 0) {
				TablicaWartosci[y][x] = 2;
			}
			else
			{
				TablicaWartosci[y][x] = -1;
			}
		}
	}
	for (unsigned int y = 0; y < wysokosc; y++)
	{
		for (unsigned int x = 0; x < szerokosc; x++)
		{
			MapaJednowymiarowa.push_back(TablicaWartosci[y][x]);
		}
	}
}

void Mapa::WypiszPola()
{
	/*for (unsigned int y = 0; y < wysokosc; y++)
	{
		for (unsigned int x = 0; x < szerokosc; x++)
		{
			std::cout << TablicaWartosci[y][x] << " ";
		}
		std::cout << std::endl;
	}*/
	for (int i = 0; i < MapaJednowymiarowa.size(); ++i)
	{
		std::cout << MapaJednowymiarowa[i] << " ";
		if ((i+1)%szerokosc == 0)
		{
			std::cout<< "" << std::endl;
		}
	}
}
