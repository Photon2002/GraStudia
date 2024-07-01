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
}

Pocisk::Pocisk(const Pocisk& pocisk)
{
    PozycjaPocisku = pocisk.PozycjaPocisku;
    TeksturaPocisku = pocisk.TeksturaPocisku;
    predkosc = pocisk.predkosc;
    zasieg = pocisk.zasieg;
    promien = pocisk.promien;
    KolizjaPocisku = pocisk.KolizjaPocisku;
    SpritePocisku = pocisk.SpritePocisku;
}