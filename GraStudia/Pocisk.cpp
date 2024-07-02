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
    SpritePocisku.setTexture(TeksturaPocisku);
    SpritePocisku.setPosition(gracz.getPosition() + sf::Vector2f(1.75f, 2.f));
    KolizjaPocisku.setRadius(promien);
    KolizjaPocisku.setFillColor(sf::Color::Red);
    KolizjaPocisku.setPosition(gracz.getPosition() + sf::Vector2f(1.75f, 2.f));
}

void Pocisk::RysujPocisk(sf::RenderWindow& window)
{
    window.draw(SpritePocisku);
}

void Pocisk::AktualizujPozycje(const Gracz& gracz)
{
    SpritePocisku.setPosition(gracz.getPosition() + sf::Vector2f(1.75f, 2.f));
    KolizjaPocisku.setPosition(gracz.getPosition() + sf::Vector2f(1.75f, 2.f));


    sf::Vector2f lotPocisku(0.f, 0.f);
}

Pocisk::Pocisk(const Pocisk& pocisk)
{
    PozycjaPocisku = pocisk.PozycjaPocisku;
    TeksturaPocisku = pocisk.TeksturaPocisku;
    predkoscPocisku = pocisk.predkoscPocisku;
    zasieg = pocisk.zasieg;
    promien = pocisk.promien;
    KolizjaPocisku = pocisk.KolizjaPocisku;
    SpritePocisku = pocisk.SpritePocisku;
}

bool Pocisk::czyPozaZasiegiem(const Gracz& gracz)
{
    sf::Vector2f pozycjaGracza = gracz.getPosition();
    float odleglosc = std::sqrt(std::pow(PozycjaPocisku.x - pozycjaGracza.x, 2) + std::pow(PozycjaPocisku.y - pozycjaGracza.y, 2));

    if (odleglosc > zasieg)
    {
        return true;
    }
}

void Pocisk::Strzal(sf::RenderWindow& window, std::vector<Pocisk>& pociski)
{
    
    Pocisk nowyPocisk(*this); 
    pociski.push_back(nowyPocisk);
    std::cout << "Narysowalem pocisk!" << std::endl;

}

void Pocisk::LotPocisku(const sf::Time& dt)
{
    sf::Vector2f poruszanie(0.f, 0.f);
    poruszanie.x += predkoscPocisku * dt.asSeconds();
    SpritePocisku.move(poruszanie);
}

Pocisk::~Pocisk()
{
}