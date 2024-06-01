#include <SFML/Graphics.hpp>
#include "Mapa.h"
#include "Plansza.h"
#include "postac.h"
#include "gracz.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1024, 1024), "SFML GAME");
    Mapa mapa1("assets/mapa2.png");
    Gracz gracz("assets/gracz.png", 50.f, 50.f, 500.f);
    sf::Clock clock;
    sf::View view(sf::FloatRect(0, 0, 300, 300));
    mapa1.WypiszPola();
    Plansza pola;
    if (!pola.load("assets/paleta.png", sf::Vector2u(32, 32), mapa1.MapaJednowymiarowa, mapa1.szerokosc, mapa1.wysokosc))
        return -1;
    while (window.isOpen())
    {
        sf::Event event;
        sf::Time dt = clock.restart();
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        gracz.Aktualizacja(dt);
        sf::Vector2f graczPos = gracz.getPosition();
        view.setCenter(graczPos);

        window.clear();
        window.draw(pola);
        window.setView(view);
        gracz.RysujSpritea(window);
        window.display();
    }
    
    return 0;
}
