
#ifndef FIGURA_H
#define FIGURA_H

#include <Struktury_danych.h>
class Plansza;
class Figura:public sf::Sprite
{
private:
    Plansza *plansza;

public:

    void Ruch();

    void Posible_move();

    void DrawPozycja(const sf::Color &C,const short &X1,const short &Y1);

    void Skalowanie(sf::RenderWindow &window,const short&x,const short&y);

    void Ustaw(sf::RenderWindow &window,const short&x,const short&y,short &X1,short &Y1 );

    void Parametry(sf::RenderWindow &window,sf::RectangleShape &rec,
                   const short &x,const short &y);

    void Rysowanie_Plansza(sf::RenderWindow &window,const sf::Color &Pole1,const sf::Color &Pole2,
                           sf::RectangleShape &Pole,const short &x,const short &y);

    void SetDisplay(sf::RenderWindow &window,sf::Vector2i (a)=sf::Vector2i(0,0),
                    sf::Vector2u(c)=sf::Vector2u(0,0),bool D=0);//pozwala ustawić okno do rozmiarów ekranu


    Figura(std::string N, short x1, short y1,const u_short &t);

    u_short team;//do jakiej drużyny należy
    short X,Y; //pozycja XY względem planszy
    short textureX, textureY;//rozmiary tekstury
    bool King=0, CanDestroy=1, NotWasMoved=1, IsSelect=0;
    std::string NazwaTekstury; //na podstawie nazwy będzie wiadomo, jaka to jest figura i względem tej figury będzie czytane vector<struct> z możliwymi ruchami
};





#endif // FIGURA_H
