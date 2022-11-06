#include "Plansza.h"
#include "funkcje.h"
#include "przycisk.h"
#include "Zdarzenia.h"
int main()
{
    srand(time(NULL));
    sf::Clock clock;
    sf::RenderWindow window(sf::VideoMode(1,1), "Szachy");
    SetDisplay(window,sf::Vector2i(50,50),sf::Vector2u(sf::VideoMode::getDesktopMode().width-100,sf::VideoMode::getDesktopMode().height-100));

    while(window.isOpen())
    {
        sf::Event event;

        switch (okienko)
        {
            case 1:
        {
            //Okienko startowe
            sf::Texture tlo_textura;
            if (!tlo_textura.loadFromFile("backgroud/Okienko_startowe.png")) {
                return 1;
            }
            sf::Sprite tlo;
            tlo.setTexture(tlo_textura);
            tlo.setPosition(0,0);
            tlo.setScale(window.getView().getSize().x/tlo_textura.getSize().x,window.getView().getSize().y/tlo_textura.getSize().y);



            Przycisk test1(window,sf::Vector2f(0.4,0.3),sf::Vector2f(0.6,0.45));
            Przycisk test2(window,sf::Vector2f(0.4,0.55),sf::Vector2f(0.6,0.7));
            while(okienko==1) //gra_start
                {
            akcja_gra_start (window,event,okienko);

            window.draw(tlo);
            window.draw(test1);
            window.draw(test2);
            window.display();
                }
        }
            break;
            case 2://gra_szachy
            {

                Plansza Plansza(window,event);
                Plansza.Gra();
        }
            break;
            default: return 0;
        }
    }
return 0;

}
