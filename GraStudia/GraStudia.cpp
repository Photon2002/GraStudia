#include <SFML/Graphics.hpp>
#include "Mapa.h"
#include "Plansza.h"
#include "postac.h"
#include "gracz.h"
#include "Pocisk.h"
#include "KolizjaMapy.h"

bool checkCollision(const sf::RectangleShape& rect1, const sf::RectangleShape& rect2) {
    // Pobierz globalne prostokąty kolizji
    sf::FloatRect rect1Bounds = rect1.getGlobalBounds();
    sf::FloatRect rect2Bounds = rect2.getGlobalBounds();

    // Sprawdź kolizję między prostokątami
    return rect1Bounds.intersects(rect2Bounds);
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(1024, 1024), "SFML GAME");
    Mapa mapa1("assets/mapa2.png");
    Gracz gracz("assets/gracz.png", 70.f, 130.f, 500.f);
    Pocisk jablko("assets/pocisk.png", gracz, 1000.f);
    sf::Clock clock;
    sf::View view(sf::FloatRect(0, 0, 300, 300));
    mapa1.WypiszPola();
    KolizjaMapy polaKolizji;
    Plansza pola;
    bool czyPrzeciecie = false;

    if (!pola.load("assets/paleta.png", sf::Vector2u(32, 32), mapa1.MapaJednowymiarowa, mapa1.szerokosc, mapa1.wysokosc))
        return -1;
    if (!polaKolizji.kolizja(sf::Vector2u(32, 32), mapa1.MapaKolizji, mapa1.szerokosc, mapa1.wysokosc))
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
        jablko.AktualizujPozycje(gracz);
        sf::Vector2f graczPos = gracz.getPosition();
        view.setCenter(graczPos);

        

        for (int i = 0; i < polaKolizji.ListaObiektowKolizyjnych.size(); i++)
        {
            czyPrzeciecie = checkCollision(gracz.KolizjaGracza, polaKolizji.ListaObiektowKolizyjnych[i]);
            if (czyPrzeciecie)
            {
                break;
            }
        }

        window.clear();
        window.draw(pola);
        window.setView(view);
        gracz.RysujSpritea(window);
        jablko.RysujPocisk(window);
        if(czyPrzeciecie == true)
        {
            gracz.setPoprzedniaPozycjaGracza(gracz.getPoprzedniaPozycjaGracza());
            gracz.KolizjaGracza.setPosition(gracz.getPoprzedniaPozycjaGracza());
            gracz.SpriteGracza.setPosition(gracz.getPoprzedniaPozycjaGracza());
        }
        window.display();
    }
    
    return 0;
}
