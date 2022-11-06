#include <Zdarzenia.h>

void akcja_gra_start (sf::RenderWindow  &window,sf::Event &Event, u_short &okienko
                      )
{
    if(window.pollEvent(Event))
    {
        if(Event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::G)) okienko=2;
    }
}
