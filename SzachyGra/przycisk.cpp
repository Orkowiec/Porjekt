#include "przycisk.h"

Przycisk::Przycisk(sf::RenderWindow &W,sf::Vector2f (pos),sf::Vector2f (roz),sf::Color C)
{

    //sf::Vector2f(W.getView().getSize().x*roz.x,W.getView().getSize().y*roz.y);
    //setSize(sf::Vector2f(W.getView().getSize().x*roz.x,W.getView().getSize().y*roz.y));
    if(pos.x>roz.x)
    {
        float x=pos.x;
        pos.x=roz.x;
        roz.x=x-pos.x;
    }
    else roz.x-=pos.x;
    if(pos.y>roz.y)
    {
        float y=pos.y;
        pos.y=roz.y;
        roz.y=y-pos.y;
    }
    else roz.y-=pos.y;
    //setSize(sf::Vector2f(W.getView().getSize().x*(std::abs(pos.x-roz.x)),W.getView().getSize().y*(std::abs(pos.y-roz.y))));
    setPosition(W.getView().getSize().x*pos.x,W.getView().getSize().y*pos.y);
    setSize(sf::Vector2f(W.getView().getSize().x*roz.x,W.getView().getSize().y*roz.y));
    setFillColor(C);
}
