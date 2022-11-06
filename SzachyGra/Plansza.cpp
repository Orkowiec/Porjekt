#include "Plansza.h"

Plansza::Plansza(sf::RenderWindow &W,sf::Event &E,std::string Nazwa_Planszy)
{
window=&W;
event=&E;
tekstury.resize(size(NazwyFigur));
for(short c=0;c<short(size(NazwyFigur));c++)
{
    tekstury[c].name=NazwyFigur[c];
    tekstury[c].texture.loadFromFile("images/"+tekstury[c].name+".png");
}

Plansza_gry.nazwa=Nazwa_Planszy;
Parametry_Planszy();

SetDisplay(sf::Vector2i(-8,-31));

Ustawienie_Figur();
Ruch_Figur();
Teraz=0;
HokusPokus=!window->hasFocus();
}
void Plansza::Parametry_Planszy() //rozmiar planszy, kolor pól
{

    std::fstream Plan("Plansze/"+Plansza_gry.nazwa+'/'+Plansza_gry.nazwa+"Plansza.txt", std::fstream::in);
    if(Plan.is_open())
    {
        std::string ruch;
        while(std::getline(Plan, ruch,';'))
        {
            Plansza_gry.board_x=(short)stoi(ruch);
            std::getline(Plan, ruch,';');
            Plansza_gry.board_y=(short)stoi(ruch);
            std::getline(Plan, ruch,',');
            Plansza_gry.Pole1.r=(UINT8)stoi(ruch);
            std::getline(Plan, ruch,',');
            Plansza_gry.Pole1.g=(UINT8)stoi(ruch);
            std::getline(Plan, ruch,',');
            Plansza_gry.Pole1.b=(UINT8)stoi(ruch);
            std::getline(Plan, ruch,';');
            Plansza_gry.Pole1.a=(UINT8)stoi(ruch);
            std::getline(Plan, ruch,',');
            Plansza_gry.Pole2.r=(UINT8)stoi(ruch);
            std::getline(Plan, ruch,',');
            Plansza_gry.Pole2.g=(UINT8)stoi(ruch);
            std::getline(Plan, ruch,',');
            Plansza_gry.Pole2.b=(UINT8)stoi(ruch);
            std::getline(Plan, ruch,';');
            Plansza_gry.Pole2.a=(UINT8)stoi(ruch);
        }
    }

}
void Plansza::SetDisplay(sf::Vector2i(a),sf::Vector2u(c))
{
   window->setSize(c);
   window->setPosition(a);
}
void Plansza::Ustawienie_Figur()
{
std::fstream Ustawienie("Plansze/"+Plansza_gry.nazwa+'/'+Plansza_gry.nazwa+"UstawienieFigur.txt", std::fstream::in);
if(Ustawienie.is_open())
{
        std::string nazwa;
        short x,y;
        u_short t;
        std::string Pozycja;
        std::getline(Ustawienie, Pozycja,',');
        while(std::getline(Ustawienie, Pozycja,','))
        {
            //std::cout<<Pozycja<<std::endl;
            nazwa=Pozycja;
            std::getline(Ustawienie, Pozycja,',');
            //std::cout<<Pozycja<<std::endl;
            x=(short)stoi(Pozycja);
            std::getline(Ustawienie, Pozycja,',');
            //std::cout<<Pozycja<<std::endl;
            y=(short)stoi(Pozycja);
            std::getline(Ustawienie, Pozycja,',');
            //std::cout<<Pozycja<<std::endl;
            t=(u_short)stoi(Pozycja);
            std::getline(Ustawienie, Pozycja,',');
            //std::cout<<Pozycja<<std::endl;
            figury.emplace_back(nazwa,x,y,t);
        }
    }
}
void Plansza::Ruch_Figur()
{
    for(auto &T:tekstury)
    {
        std::fstream Plik("Ruchy/"+T.name+".txt", std::fstream::in);
        if(Plik.is_open())
        {
            std::string ruch;
            while(std::getline(Plik, ruch,','))
            {   PoruszanieSie a;
                if(ruch[ruch.size()-1]!=';')
                {
                    a.x=(short)std::stoi(ruch);
                }
                else
                {
                    a.x=(short)std::stoi(ruch.erase(ruch.size()-1,1));
                    goto endloop;
                }
                std::getline(Plik, ruch,',');
                if(ruch[ruch.size()-1]!=';')
                {
                    a.y=(short)std::stoi(ruch);
                }
                else
                {
                    a.y=(short)std::stoi(ruch.erase(ruch.size()-1,1));
                    goto endloop;
                }
                std::getline(Plik, ruch,',');
                if(ruch[ruch.size()-1]!=';')
                {
                    a.EL=(u_short)std::stoi(ruch);
                }
                else
                {
                    a.EL=(u_short)std::stoi(ruch.erase(ruch.size()-1,1));
                    goto endloop;
                }
                std::getline(Plik, ruch,',');
                if(ruch[ruch.size()-1]!=';')
                {
                    a.US=(bool)std::stoi(ruch);
                }
                else
                {
                    a.US=(bool)std::stoi(ruch.erase(ruch.size()-1,1));
                    goto endloop;
                }
                std::getline(Plik, ruch,',');
                if(ruch[ruch.size()-1]!=';')
                {
                    a.UW=(bool)std::stoi(ruch);
                }
                else
                {
                    a.UW=(bool)std::stoi(ruch.erase(ruch.size()-1,1));
                    goto endloop;
                }
                std::getline(Plik, ruch,',');
                if(ruch[ruch.size()-1]!=';')
                {
                    a.Z=(bool)std::stoi(ruch);
                }
                else
                {
                    a.Z=(bool)std::stoi(ruch.erase(ruch.size()-1,1));
                    goto endloop;
                }
                std::getline(Plik, ruch,',');
                if(ruch[ruch.size()-1]!=';')
                {
                    a.ZE=(bool)std::stoi(ruch);
                }
                else
                {
                    a.ZE=(bool)std::stoi(ruch.erase(ruch.size()-1,1));
                    goto endloop;
                }
                std::getline(Plik, ruch,',');
                if(ruch[ruch.size()-1]!=';')
                {
                    a.S=(bool)std::stoi(ruch);
                }
                else
                {
                    a.S=(bool)std::stoi(ruch.erase(ruch.size()-1,1));
                    goto endloop;
                }
                std::getline(Plik, ruch,',');
                if(ruch[ruch.size()-1]!=';')
                {
                    a.SE=(bool)std::stoi(ruch);
                }
                else
                {
                    a.SE=(bool)std::stoi(ruch.erase(ruch.size()-1,1));
                    goto endloop;
                }
                std::getline(Plik, ruch,',');
                if(ruch[ruch.size()-1]!=';')
                {
                    a.M=(bool)std::stoi(ruch);
                }
                else
                {
                    a.M=(bool)std::stoi(ruch.erase(ruch.size()-1,1));
                    goto endloop;
                }
                std::getline(Plik, ruch,',');
                if(ruch[ruch.size()-1]!=';')
                {
                    a.T=(bool)std::stoi(ruch);
                }
                else
                {
                    a.T=(bool)std::stoi(ruch.erase(ruch.size()-1,1));
                }
             endloop:
                T.Dane.emplace_back(a);
            }
        }
    }
}
bool Plansza::Select ()//pozwoli przeszukiwać, czy jest jakaś figura wybrana
{ for(auto &F:figury) if(F.IsSelect==1) return 1;
    return 0;
}
void Plansza::Parametry()
{
    float wx=window->getSize().x,wy=window->getSize().y;
    Rysunek.setScale(window->getView().getSize().x/wx,window->getView().getSize().y/wy); //skaluje elementy do zmiany rozmiaru okna (View!=Size)
    if(wy<wx) wx=wy; else wy=wx; //rysowanie jest polem kwadratowym niezależnie od ilości na danym boku elementów
    Rysunek.setSize(sf::Vector2f(wx/Plansza_gry.board_x,wy/Plansza_gry.board_y));
}
void Plansza::Rysowanie_Plansza()
{
    float wx=window->getSize().x,wy=window->getSize().y;
    Rysunek.setScale(window->getView().getSize().x/wx,window->getView().getSize().y/wy); //skaluje elementy do zmiany rozmiaru okna (View!=Size)
    if(wy<wx) wx=wy; else wy=wx; //rysowanie jest polem kwadratowym niezależnie od ilości na danym boku elementów
    Rysunek.setPosition(0,0);
    Rysunek.setSize(sf::Vector2f(wx,wy));
    Rysunek.setFillColor(Plansza_gry.Pole1);
    window->draw(Rysunek);
    Rysunek.setFillColor(Plansza_gry.Pole2);
    Rysunek.setSize(sf::Vector2f(wx/Plansza_gry.board_x,wy/Plansza_gry.board_y));
    for (short c=0;c < Plansza_gry.board_y;c++ )
    {
        for(short d=0;d<Plansza_gry.board_x;d++)
        {
            if((c+d)%2==0)
            {
                Rysunek.setPosition((d%Plansza_gry.board_x)*window->getView().getSize().x*wx/Plansza_gry.board_x/window->getSize().x,(c%Plansza_gry.board_y)*window->getView().getSize().y*wy/Plansza_gry.board_y/window->getSize().y);
                window->draw(Rysunek);
            }
        }
    }
}
void Plansza::Zdarzenia_Podstawowe()
{
    if(window->pollEvent(*event))
    {
        if(event->type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {window->close(); okienko=0;}
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::G)) okienko=2;
    }
}
void Plansza::Gra()
{
    while(okienko==2)
    {
        sf::Time elapsed;
        akcja_gra_szachy();

        if((event->mouseButton.button == sf::Mouse::Left)||Zmiana_okna!=window->getSize()||window->hasFocus()!=HokusPokus)
            {
             window->clear();
             Rysowanie_Plansza();
             for(auto &Figury : figury)
             {
               Figury.Ustaw(*window,Plansza_gry.board_x,Plansza_gry.board_y,Figury.X,Figury.Y);
                if(Zmiana_okna!=window->getSize())Figury.Skalowanie(*window,Plansza_gry.board_x,Plansza_gry.board_y);

              window->draw(Figury);
           }

           for(auto &Figury : figury)
           {
               if(Figury.IsSelect) Figury.Posible_move();
           }

          if(Zmiana_okna!=window->getSize()||HokusPokus==window->hasFocus()){Zmiana_okna=window->getSize(); HokusPokus=window->hasFocus();}
           window->display();
     }
    }
}
void Plansza::akcja_gra_szachy()
{
    while (window->pollEvent(*event))
    {
        if (event->type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window->close();
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) okienko=1;
        if (event->type == sf::Event::MouseButtonPressed)
        {

            sf::Vector2f mouse_position = window->mapPixelToCoords(sf::Mouse::getPosition(*window));
            if(event->mouseButton.button == sf::Mouse::Left) for(auto &Figury : figury)
            {
                if(Figury.getGlobalBounds().contains(mouse_position) && Select()==Figury.IsSelect &&Figury.team==Teraz)
                Figury.IsSelect=1-Figury.IsSelect%2 ;//Zmienia wartość na przeciwną.
                Figury.Ruch();//Ruch figury
            }

        }
    }
}
