#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

class Mapa
{
	public:
		Mapa(const std::string& sciezkaPliku);
		void WypiszPola();
		std::vector<int> MapaJednowymiarowa;
		unsigned int szerokosc;
		unsigned int wysokosc;
	private:
		sf::Image mapa;
		std::vector<std::vector<int>> TablicaWartosci;
		void WczytajMape();
};

