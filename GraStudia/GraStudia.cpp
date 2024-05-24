#include <SFML/Graphics.hpp>
#include "Mapa.h"


int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML GAME");
    Mapa mapa1("assets/mapa.png");
    mapa1.WypiszPola();
    /*while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.display();
    }*/

    return 0;
}
