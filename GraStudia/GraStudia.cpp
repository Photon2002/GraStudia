#include <SFML/Graphics.hpp>
#include "Mapa.h"
#include "Plansza.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1024, 1024), "SFML GAME");
    Mapa mapa1("assets/mapa2.png");
    mapa1.WypiszPola();
    Plansza pola;
    if (!pola.load("assets/paleta.png", sf::Vector2u(32, 32), mapa1.MapaJednowymiarowa, mapa1.szerokosc, mapa1.wysokosc))
        return -1;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(pola);
        window.display();
    }
    
    return 0;
}
