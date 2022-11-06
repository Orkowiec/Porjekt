#ifndef FUNKCJE_H
#define FUNKCJE_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "wtypes.h"
#include <iostream>
#include <fstream>
void SetDisplay(sf::RenderWindow &window,sf::Vector2i (a)=sf::Vector2i(0,0),
                sf::Vector2u(c)=sf::Vector2u(sf::VideoMode::getDesktopMode().width,sf::VideoMode::getDesktopMode().height));//pozwala ustawić okno do rozmiarów ekranu

#endif // FUNKCJE_H
