#include "figura.h"
#include "Plansza.h"
Figura::Figura(std::string N, short x1, short y1,const u_short &t)
{    X=x1,Y=y1;
    team=t;
    std::string abc=plansza->tekstury[2].name;
    for(short c=0;c<short(plansza->tekstury.size());c++)
    {
        if(plansza->tekstury[c].name==N)
        {
            setTexture(plansza->tekstury[c].texture);
            textureX=plansza->tekstury[c].texture.getSize().x;
            textureY=plansza->tekstury[c].texture.getSize().y;
            NazwaTekstury=plansza->tekstury[c].name;
            break;
        }
    }
 Skalowanie(*plansza->window,plansza->Plansza_gry.board_x,plansza->Plansza_gry.board_y);
 Ustaw(*plansza->window,plansza->Plansza_gry.board_x,plansza->Plansza_gry.board_y,X,Y);
}

void Figura::Ruch()
{
  if(IsSelect)
  {
    float wx=plansza->window->getSize().x,wy=plansza->window->getSize().y;
    if(wy<wx) wx=wy; else wy=wx;
     sf::Vector2f mouse_position = plansza->window->mapPixelToCoords(sf::Mouse::getPosition(*plansza->window));
    for(auto &A:plansza->tekstury) if(A.name==NazwaTekstury) for(auto &f:A.Dane)
    {
        if(!(f.M==1&&0==NotWasMoved))
        {
            short EL=f.EL;
            short X1=X+f.x, Y1=Y+f.y;
            do
                {
                    if(X1<0||Y1<0||X1>=plansza->Plansza_gry.board_x||Y1>=plansza->Plansza_gry.board_y) break;
                    short krok=-1;
                    for(auto &F:plansza->figury)
                        {
                            krok++;
                            if(F.getGlobalBounds().contains(sf::Vector2f((X1%plansza->Plansza_gry.board_x+0.5)*plansza->window->getView().getSize().x*wx/plansza->Plansza_gry.board_x/plansza->window->getSize().x,(Y1%plansza->Plansza_gry.board_y+0.5)*plansza->window->getView().getSize().y*wy/plansza->Plansza_gry.board_y/plansza->window->getSize().y)))
                            {
                                if((F.getGlobalBounds().contains(mouse_position)&& sf::Mouse::isButtonPressed(sf::Mouse::Left)))
                                {
                                if(f.Z||f.S||f.US||f.UW)
                                {
                                if ((f.US&&F.team==team)||(f.UW&&F.team!=team))goto endloop1;
                                else if(f.Z==1&&F.team!=team)
                                   {
                                    X=X1,
                                    Y=Y1;
                                    IsSelect=0;
                                    NotWasMoved=0;
                                    if(Teraz==Team-1) Teraz=0;
                                    else Teraz+=1;
                                    plansza->figury.erase(plansza->figury.begin()+krok);
                                    return;
                                   }
                                else if (f.S==1&&F.team==team)
                                  {
                                    X=X1,
                                    Y=Y1;
                                    IsSelect=0;
                                    NotWasMoved=0;
                                    if(Teraz==Team-1) Teraz=0;
                                    else Teraz+=1;
                                    plansza->figury.erase(plansza->figury.begin()+krok);
                                    return;
                                  }
                                else goto endloop;
                                }
                                }
                                if((f.SE&&F.team==team)||(f.ZE&&F.team!=team)) goto endloop;
                                else goto endloop1;
                            }
                        }

                    if(f.T==0)
                    {
                        DrawPozycja(sf::Color(0,0,0,0),X1,Y1);
                        if(plansza->Rysunek.getGlobalBounds().contains(mouse_position)&& sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    {
                        X=X1,
                        Y=Y1;
                        IsSelect=0;
                        NotWasMoved=0;
                        if(Teraz==Team-1) Teraz=0;
                        else Teraz+=1;
                        return;
                    }
                    }
                    endloop1:
                    EL--;
                    X1+=f.x;
                    Y1+=f.y;
                }
            while(EL!=0);
        endloop:;

        }
    }

  }
}

void Figura::Posible_move()
{
    DrawPozycja(plansza->Wybor1,X,Y);
    float wx=plansza->window->getSize().x,wy=plansza->window->getSize().y;
    if(wy<wx) wx=wy; else wy=wx;
    for(auto &A:plansza->tekstury) if(A.name==NazwaTekstury) for(auto &f:A.Dane)
    {
        if(!(f.M==1&&0==NotWasMoved))
        {
            short EL=f.EL;
            short X1=X+f.x, Y1=Y+f.y;
            do
                {
                    if(X1<0||Y1<0||X1>=plansza->Plansza_gry.board_x||Y1>=plansza->Plansza_gry.board_y) break;
                    for(auto &F:plansza->figury)
                        {
                            if(F.getGlobalBounds().contains(sf::Vector2f((X1%plansza->Plansza_gry.board_x+0.5)*plansza->window->getView().getSize().x*wx/plansza->Plansza_gry.board_x/plansza->window->getSize().x,(Y1%plansza->Plansza_gry.board_y+0.5)*plansza->window->getView().getSize().y*wy/plansza->Plansza_gry.board_y/plansza->window->getSize().y)))
                            {
                                if(f.Z||f.S||f.US||f.UW)
                                {
                                if ((f.US&&F.team==team)||(f.UW&&F.team!=team))goto endloop1;
                                else if(f.Z==1&&F.team!=team)
                                   {
                                       DrawPozycja(plansza->Wybor2,X1,Y1);
                                   }
                                else if (f.S==1&&F.team==team)
                                  {
                                      DrawPozycja(plansza->Wybor2,X1,Y1);
                                  }
                                else goto endloop;
                                }
                                if((f.SE&&F.team==team)||(f.ZE&&F.team!=team)) goto endloop;
                                else goto endloop1;

                            }
                        }

                    if(f.T==0)
                        DrawPozycja(plansza->Wybor3,X1,Y1);
                    endloop1:
                    EL--;
                    X1+=f.x;
                    Y1+=f.y;
                }
            while(EL!=0);
        endloop:;
        }
    }
}

void Figura::DrawPozycja(const sf::Color &C,const short &X1,const short &Y1)
{   if(X1<0||Y1<0||X1>=plansza->Plansza_gry.board_x||Y1>=plansza->Plansza_gry.board_y) return;
    float wx=plansza->window->getSize().x,wy=plansza->window->getSize().y;
    if(wy<wx) wx=wy; else wy=wx;
    plansza->Rysunek.setPosition((X1%plansza->Plansza_gry.board_x)*plansza->window->getView().getSize().x*wx/plansza->Plansza_gry.board_x/plansza->window->getSize().x,(Y1%plansza->Plansza_gry.board_y)*plansza->window->getView().getSize().y*wy/plansza->Plansza_gry.board_y/plansza->window->getSize().y);
    plansza->Rysunek.setFillColor(sf::Color(C));
    plansza->window->draw(plansza->Rysunek);
}

void Figura::Skalowanie(sf::RenderWindow &window,const short&x,const short&y)
{
    float wx=window.getSize().x,wy=window.getSize().y;
    if(wy<wx) wx=wy; else wy=wx;
    setScale(window.getView().getSize().x/textureX*wx/(x*window.getSize().x),
             window.getView().getSize().y/textureY*wy/(y*window.getSize().y));
}

void Figura::Ustaw(sf::RenderWindow &window,const short&x,const short&y,short &X1,short &Y1 )
{
    float wx=window.getSize().x,wy=window.getSize().y;
    if(wy<wx) wx=wy; else wy=wx;
    setPosition((X1%x)*window.getView().getSize().x*wx/x/window.getSize().x,(Y1%y)*window.getView().getSize().y*wy/y/window.getSize().y);
}


