#ifndef PRZYCISK_H
#define PRZYCISK_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "wtypes.h"

class Przycisk :public sf::RectangleShape
{
public:
    Przycisk(sf::RenderWindow &W,sf::Vector2f (pos)=sf::Vector2f(0,0),
             sf::Vector2f (roz)=sf::Vector2f(0,0),sf::Color C=sf::Color::Green);
    bool IsSelect=0;

};

#endif // PRZYCISK_H
