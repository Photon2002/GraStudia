#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

class Mapa
{
	public:
		Mapa(const std::string& sciezkaPliku);
		void WypiszPola();
	private:
		sf::Image mapa;
		unsigned int szerokosc;
		unsigned int wysokosc;
		std::vector<std::vector<int>> TablicaWartosci;
		void WczytajMape();
};

