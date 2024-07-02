#include "Pocisk.h"
#include "gracz.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

Pocisk::Pocisk(const std::string& texturePath, const Gracz& gracz, float szybkosc)
{
    if (!TeksturaPocisku.loadFromFile(texturePath))
    {
        perror("Blad tekstury!");
    }
    if (czyKopia == false)
    {
        SpritePocisku.setTexture(TeksturaPocisku);
        SpritePocisku.setPosition(gracz.getPosition() + sf::Vector2f(1.75f, 2.f));
        KolizjaPocisku.setRadius(promien);
        KolizjaPocisku.setFillColor(sf::Color::Red);
        KolizjaPocisku.setPosition(gracz.getPosition() + sf::Vector2f(1.75f, 2.f));
    }
}

void Pocisk::RysujPocisk(sf::RenderWindow& window)
{
        //window.draw(SpritePocisku);
        window.draw(KolizjaPocisku);
}

void Pocisk::AktualizujPozycje(const Gracz& gracz)
{
    if (czyKopia == false)
    {
        SpritePocisku.setPosition(gracz.getPosition() + sf::Vector2f(1.75f, 2.f));
        KolizjaPocisku.setPosition(gracz.getPosition() + sf::Vector2f(1.75f, 2.f));
    }
    else
    {
        sf::Vector2f lotPocisku(0.f, 0.f);
    }

}

Pocisk::Pocisk(const Pocisk& pocisk)
{
    PozycjaPocisku = pocisk.PozycjaPocisku;
    TeksturaPocisku = pocisk.TeksturaPocisku;
    predkoscPocisku = pocisk.predkoscPocisku;
    zasieg = pocisk.zasieg;
    czyKopia = true;
    promien = pocisk.promien;
    KolizjaPocisku = pocisk.KolizjaPocisku;
    SpritePocisku = pocisk.SpritePocisku;
}

/*bool Pocisk::czyPozaZasiegiem(const Gracz& gracz) const
{
    sf::Vector2f pozycjaGracza = gracz.getPosition();
    float odleglosc = std::sqrt(std::pow(PozycjaPocisku.x - pozycjaGracza.x, 2) + std::pow(PozycjaPocisku.y - pozycjaGracza.y, 2));

    if (odleglosc > zasieg)
    {
        return true;
    }

    return false;
}*/

void Pocisk::Strzal(sf::RenderWindow& window, std::vector<Pocisk>& pociski, const Gracz& gracz)
{
    
    Pocisk nowyPocisk(*this);
    nowyPocisk.czyKopia = true;
    pociski.push_back(nowyPocisk);
    
    switch (gracz.kierunek_postaci)
    {
    case Gracz::Kierunek::W_GORE:
        kierunekLotu = 1;
        break;
    case Gracz::Kierunek::W_DOL:
        kierunekLotu = 2;
        break;
    case Gracz::Kierunek::W_LEWO:
        kierunekLotu = 3;
        break;
    case Gracz::Kierunek::W_PRAWO:
        kierunekLotu = 4;
        break;
    }
    std::cout << "Narysowalem pocisk!" << std::endl;

}

void Pocisk::LotPocisku(const sf::Time& dt)
{
    sf::Vector2f poruszaniePocisku(0.f, 0.f);
    
    switch (kierunekLotu)
    {
        case 1:
            poruszaniePocisku.y -= predkoscPocisku * dt.asSeconds();
        case 2:
            poruszaniePocisku.y += predkoscPocisku * dt.asSeconds();
        case 3:
            poruszaniePocisku.x -= predkoscPocisku * dt.asSeconds();
        case 4:
            poruszaniePocisku.x += predkoscPocisku * dt.asSeconds();
    }
    SpritePocisku.move(poruszaniePocisku);
    KolizjaPocisku.move(poruszaniePocisku);
}

Pocisk::~Pocisk()
{
    std::cout << "Destruktor Pocisk wywolany!" << std::endl;
}