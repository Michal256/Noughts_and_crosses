//© All rights reserved @2017 Author: Michał Ziółek.
//Application is using Simple and Fast Multimedia Library (SFML)
/*
Warning:
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
#include <iostream>
#include <string>
#include <windows.h>
#include <SFML/Graphics.hpp>

void showCharm(const bool &chplayerclicked,sf::Sprite &spriteznakm,const sf::Texture &znakmalyo,const sf::Texture &znakmalyx,bool &zmianapola,bool &bootload,short int rodzaj,short int &ruch,short int &temporary);
short int chopposite(const int tabactive[],short int nr,short int priority);
short int atakiobrona(int tabactive[],short int &where);
using std::cout;
using std::cin;
using std::endl;

int main()
{

    sf::Vector2i vc1(800,600);
    sf::RenderWindow Window;
    Window.create(sf::VideoMode(vc1.x,vc1.y),"Noughts and Crosses",sf::Style::Titlebar|sf::Style::Close);

    sf::Font font;
    if(!font.loadFromFile("lucon.ttf"))
    {
        exit(0);
    }

    sf::Texture tlo;
    if(!tlo.loadFromFile("img/tlo.png"))
       {
        exit(0);
       }

    sf::Sprite spritetlo;
    spritetlo.setTexture(tlo);




    sf::RectangleShape chtryb(sf::Vector2f(280,100));
    chtryb.setPosition(vc1.x/2-140,100);
    chtryb.setFillColor(sf::Color(220,220,220));
    chtryb.setOutlineColor(sf::Color(150,150,150));
    chtryb.setOutlineThickness(3);

    sf::RectangleShape chplayer(sf::Vector2f(120,80));
    chplayer.setPosition(vc1.x/2-140,350);
    chplayer.setFillColor(sf::Color(6,173,0));
    chplayer.setOutlineColor(sf::Color(150,150,150));
    chplayer.setOutlineThickness(3);

    sf::RectangleShape chplayer2(sf::Vector2f(120,80));
    chplayer2.setPosition(vc1.x/2+20,350);
    chplayer2.setFillColor(sf::Color(220,220,220));
    chplayer2.setOutlineColor(sf::Color(150,150,150));
    chplayer2.setOutlineThickness(3);

    sf::RectangleShape Button01(sf::Vector2f(180,80));
    Button01.setPosition(580,480);
    Button01.setFillColor(sf::Color(6,71,191));
    Button01.setOutlineColor(sf::Color(150,150,150));
    Button01.setOutlineThickness(3);

    sf::RectangleShape Button02(sf::Vector2f(180,80));
    Button02.setPosition(360,480);
    Button02.setFillColor(sf::Color(230,0,27));
    Button02.setOutlineColor(sf::Color(150,150,150));
    Button02.setOutlineThickness(3);


    sf::String tresc1=L"Wybierz tryb:";
    sf::Text tekst1(tresc1,font,38);
    tekst1.setPosition(vc1.x/2-151,20);
    tekst1.setColor(sf::Color::White);
    tekst1.setStyle(sf::Text::Bold);

    sf::String tresc2=L"Gracz vs Komputer";
    sf::Text tekst2(tresc2,font,24);
    tekst2.setPosition((vc1.x/2-140)+10,128);
    tekst2.setColor(sf::Color::Black);
    tekst2.setStyle(sf::Text::Bold|sf::Text::Italic);

    sf::String tresc3=L"Zaczyna:";
    sf::Text tekst3(tresc3,font,29);
    tekst3.setPosition(vc1.x/2-68,300);//136
    tekst3.setColor(sf::Color::White);
    tekst3.setStyle(sf::Text::Bold);

    sf::String tresc4=L"O";
    sf::Text tekst4(tresc4,font,50);
    tekst4.setPosition(vc1.x/2-95,355);
    tekst4.setColor(sf::Color::Black);
    tekst4.setStyle(sf::Text::Bold);

    sf::String tresc5=L"X";
    sf::Text tekst5(tresc5,font,50);
    tekst5.setPosition(vc1.x/2+65,355);
    tekst5.setColor(sf::Color::Black);
    tekst5.setStyle(sf::Text::Bold);

    sf::String tresc6=L"O-Gracz\nX-Komputer";
    sf::Text tekst6(tresc6,font,25);
    tekst6.setPosition(20,450);
    tekst6.setColor(sf::Color::White);
    tekst6.setStyle(sf::Text::Bold|sf::Text::Italic);

    sf::String tresc7=L"Start";
    sf::Text tekst7(tresc7,font,30);
    tekst7.setPosition(622,495);
    tekst7.setColor(sf::Color::White);
    tekst7.setStyle(sf::Text::Bold);

    sf::String tresc8=L"Wyjdź";
    sf::Text tekst8(tresc8,font,30);
    tekst8.setPosition(402,495);
    tekst8.setColor(sf::Color::White);
    tekst8.setStyle(sf::Text::Bold);

    sf::String tresc9=L"";
    sf::Text tekst9(tresc9,font,20);
    tekst9.setPosition(556,440);
    tekst9.setColor(sf::Color::White);//114
    tekst9.setStyle(sf::Text::Bold);


    bool chtrybclicked=false;
    bool chplayerclicked=0;
    bool kopiaplayerclicked=0;








    sf::Texture znakmalyo;
    sf::Texture znakmalyx;
    sf::Texture znako;
    sf::Texture znakx;
    if(!znakmalyo.loadFromFile("img/mko.png"))
    {
        exit(0);
    }
    if(!znakmalyx.loadFromFile("img/mkr.png"))
    {
        exit(0);
    }
    if(!znako.loadFromFile("img/ko.png"))
    {
        exit(0);
    }
    if(!znakx.loadFromFile("img/kr.png"))
    {
        exit(0);
    }

    sf::Sprite spriteznakm;
    spriteznakm.setPosition(600,40);

    sf::Sprite spriteznak;

    sf::RectangleShape Box1(sf::Vector2f(100,100));
    Box1.setPosition(50,50);
    Box1.setFillColor(sf::Color(180,180,180));
    Box1.setOutlineColor(sf::Color(150,150,150));
    Box1.setOutlineThickness(4);

    sf::RectangleShape Box2(sf::Vector2f(100,100));
    Box2.setPosition(200,50);
    Box2.setFillColor(sf::Color(180,180,180));
    Box2.setOutlineColor(sf::Color(150,150,150));
    Box2.setOutlineThickness(4);

    sf::RectangleShape Box3(sf::Vector2f(100,100));
    Box3.setPosition(350,50);
    Box3.setFillColor(sf::Color(180,180,180));
    Box3.setOutlineColor(sf::Color(150,150,150));
    Box3.setOutlineThickness(4);

    sf::RectangleShape Box4(sf::Vector2f(100,100));
    Box4.setPosition(50,200);
    Box4.setFillColor(sf::Color(180,180,180));
    Box4.setOutlineColor(sf::Color(150,150,150));
    Box4.setOutlineThickness(4);

    sf::RectangleShape Box5(sf::Vector2f(100,100));
    Box5.setPosition(200,200);
    Box5.setFillColor(sf::Color(180,180,180));
    Box5.setOutlineColor(sf::Color(150,150,150));
    Box5.setOutlineThickness(4);

    sf::RectangleShape Box6(sf::Vector2f(100,100));
    Box6.setPosition(350,200);
    Box6.setFillColor(sf::Color(180,180,180));
    Box6.setOutlineColor(sf::Color(150,150,150));
    Box6.setOutlineThickness(4);

    sf::RectangleShape Box7(sf::Vector2f(100,100));
    Box7.setPosition(50,350);
    Box7.setFillColor(sf::Color(180,180,180));
    Box7.setOutlineColor(sf::Color(150,150,150));
    Box7.setOutlineThickness(4);

    sf::RectangleShape Box8(sf::Vector2f(100,100));
    Box8.setPosition(200,350);
    Box8.setFillColor(sf::Color(180,180,180));
    Box8.setOutlineColor(sf::Color(150,150,150));
    Box8.setOutlineThickness(4);

    sf::RectangleShape Box9(sf::Vector2f(100,100));
    Box9.setPosition(350,350);
    Box9.setFillColor(sf::Color(180,180,180));
    Box9.setOutlineColor(sf::Color(150,150,150));
    Box9.setOutlineThickness(4);

    sf::RectangleShape Button11(sf::Vector2f(180,80));
    Button11.setPosition(600,370);
    Button11.setFillColor(sf::Color(6,71,191));
    Button11.setOutlineColor(sf::Color(150,150,150));
    Button11.setOutlineThickness(3);

    sf::RectangleShape Button12(sf::Vector2f(180,80));
    Button12.setPosition(600,470);
    Button12.setFillColor(sf::Color(230,0,27));
    Button12.setOutlineColor(sf::Color(150,150,150));
    Button12.setOutlineThickness(3);



    sf::String tresc11=L"Ruch: ";
    sf::Text tekst11(tresc11,font,30);
    tekst11.setPosition(500,50);
    tekst11.setColor(sf::Color::White);
    tekst11.setStyle(sf::Text::Bold);

    sf::String tresc12=L"";
    sf::Text tekst12(tresc12,font,35);
    tekst12.setPosition(50,500);
    tekst12.setFillColor(sf::Color::White);
    tekst12.setStyle(sf::Text::Bold);

    sf::String tresc13=L"Restart";//127
    sf::Text tekst13(tresc13,font,30);
    tekst13.setPosition(625,386);
    tekst13.setColor(sf::Color::White);
    tekst13.setStyle(sf::Text::Bold);

    sf::String tresc14=L"Wróć";//73
    sf::Text tekst14(tresc14,font,30);
    tekst14.setPosition(653,486);
    tekst14.setColor(sf::Color::White);
    tekst14.setStyle(sf::Text::Bold);












    short int tryb=0;
     int tabactive[9]={-1,-1,-1,-1,-1,-1,-1,-1,-1};

     bool zmianapola=false;
     bool bootload=false;
     bool botstart=false;
     short int temporary=0;
     bool blockclick=false;
     short int ruch=0;
     bool sekwkolko=false;
     short int przywroctemp=0;
     short int ruch1=-1;
     short int ruch2=-1;

    while(Window.isOpen())
    {


        sf::Event event;
        while(Window.pollEvent(event))
        {
            switch(event.type)
            {
                    case sf::Event::Closed:
                    {
                    Window.close();
                    break;
                    }


                    case sf::Event::MouseButtonPressed:
                        {
                            if(event.mouseButton.button==sf::Mouse::Left)
                            {
                            sf::Vector2i mms(0,0);
                            mms.x=event.mouseButton.x;
                            mms.y=event.mouseButton.y;
                            if(tryb==0)
                            {

                                if((mms.x>=260&&mms.x<=540)&&(mms.y>=100&&mms.y<=200))
                                {
                                    if(chtrybclicked==false)
                                    {
                                    chtryb.setFillColor(sf::Color(6,173,0));
                                    chtrybclicked=true;
                                    }
                                    else
                                    {
                                    chtryb.setFillColor(sf::Color(220,220,220));
                                    chtrybclicked=false;
                                    }
                                }

                                if((mms.x>=260&&mms.x<=380)&&(mms.y>=350&&mms.y<=430)&&chplayerclicked!=0)
                                {
                                chplayer.setFillColor(sf::Color(6,173,0));
                                chplayer2.setFillColor(sf::Color(220,220,220));
                                chplayerclicked=0;
                                }

                                if((mms.x>=420&&mms.x<=540)&&(mms.y>=350&&mms.y<=430)&&chplayerclicked!=1)
                                {
                                chplayer.setFillColor(sf::Color(220,220,220));
                                chplayer2.setFillColor(sf::Color(6,173,0));
                                chplayerclicked=1;
                                }

                                if((mms.x>=580&&mms.x<=760)&&(mms.y>=480&&mms.y<=560))
                                {
                                    if(chtrybclicked==true)
                                    {
                                        tresc9="";
                                        tekst9.setString(tresc9);
                                        cout<<"start"<<endl;
                                        tryb=1;
                                        showCharm(chplayerclicked,spriteznakm,znakmalyo,znakmalyx,zmianapola,bootload,0,ruch,temporary);
                                        kopiaplayerclicked=chplayerclicked;
                                        if(chplayerclicked==1)
                                        {
                                            cout<<"Zaczyna krzyżyk!"<<endl;
                                            bootload=true;
                                            temporary=1;
                                            botstart=true;
                                        }
                                    }
                                    else
                                    {
                                        tresc9="Nie wybrano trybu!";
                                        tekst9.setString(tresc9);
                                    }
                                }

                                if((mms.x>=360&&mms.x<=540)&&(mms.y>=480&&mms.y<=560))
                                {
                                Window.close();
                                }


                            }
                            else if(tryb==1)
                            {
                                if((mms.x>=50&&mms.x<=150)&&(mms.y>=50&&mms.y<=150)&&tabactive[0]==-1&&blockclick==false)
                                {
                                    cout<<"Nr.1"<<endl;
                                    tabactive[0]=chplayerclicked;
                                    chplayerclicked=!chplayerclicked;
                                    showCharm(chplayerclicked,spriteznakm,znakmalyo,znakmalyx,zmianapola,bootload,1,ruch,temporary);

                                }

                                if((mms.x>=200&&mms.x<=300)&&(mms.y>=50&&mms.y<=150)&&tabactive[1]==-1&&blockclick==false)
                                {
                                    cout<<"Nr.2"<<endl;
                                   tabactive[1]=chplayerclicked;
                                   chplayerclicked=!chplayerclicked;
                                   showCharm(chplayerclicked,spriteznakm,znakmalyo,znakmalyx,zmianapola,bootload,1,ruch,temporary);

                                }

                                if((mms.x>=350&&mms.x<=450)&&(mms.y>=50&&mms.y<=150)&&tabactive[2]==-1&&blockclick==false)
                                {
                                    cout<<"Nr.3"<<endl;
                                    tabactive[2]=chplayerclicked;
                                    chplayerclicked=!chplayerclicked;
                                    showCharm(chplayerclicked,spriteznakm,znakmalyo,znakmalyx,zmianapola,bootload,1,ruch,temporary);

                                }

                                if((mms.x>=50&&mms.x<=150)&&(mms.y>=200&&mms.y<=300)&&tabactive[3]==-1&&blockclick==false)
                                {
                                    cout<<"Nr.4"<<endl;
                                    tabactive[3]=chplayerclicked;
                                    chplayerclicked=!chplayerclicked;
                                    showCharm(chplayerclicked,spriteznakm,znakmalyo,znakmalyx,zmianapola,bootload,1,ruch,temporary);

                                }

                                if((mms.x>=200&&mms.x<=300)&&(mms.y>=200&&mms.y<=300)&&tabactive[4]==-1&&blockclick==false)
                                {
                                    cout<<"Nr.5"<<endl;
                                    tabactive[4]=chplayerclicked;
                                    chplayerclicked=!chplayerclicked;
                                    showCharm(chplayerclicked,spriteznakm,znakmalyo,znakmalyx,zmianapola,bootload,1,ruch,temporary);
                                }

                                if((mms.x>=350&&mms.x<=450)&&(mms.y>=200&&mms.y<=300)&&tabactive[5]==-1&&blockclick==false)
                                {
                                    cout<<"Nr.6"<<endl;
                                    tabactive[5]=chplayerclicked;
                                    chplayerclicked=!chplayerclicked;
                                    showCharm(chplayerclicked,spriteznakm,znakmalyo,znakmalyx,zmianapola,bootload,1,ruch,temporary);

                                }

                                if((mms.x>=50&&mms.x<=150)&&(mms.y>=350&&mms.y<=450)&&tabactive[6]==-1&&blockclick==false)
                                {
                                    cout<<"Nr.7"<<endl;
                                    tabactive[6]=chplayerclicked;
                                    chplayerclicked=!chplayerclicked;
                                    showCharm(chplayerclicked,spriteznakm,znakmalyo,znakmalyx,zmianapola,bootload,1,ruch,temporary);

                                }

                                if((mms.x>=200&&mms.x<=300)&&(mms.y>=350&&mms.y<=450)&&tabactive[7]==-1&&blockclick==false)
                                {
                                    cout<<"Nr.8"<<endl;
                                    tabactive[7]=chplayerclicked;
                                    chplayerclicked=!chplayerclicked;
                                    showCharm(chplayerclicked,spriteznakm,znakmalyo,znakmalyx,zmianapola,bootload,1,ruch,temporary);

                                }

                                if((mms.x>=350&&mms.x<=450)&&(mms.y>=350&&mms.y<=450)&&tabactive[8]==-1&&blockclick==false)
                                {
                                    cout<<"Nr.9"<<endl;
                                    tabactive[8]=chplayerclicked;
                                    chplayerclicked=!chplayerclicked;
                                    showCharm(chplayerclicked,spriteznakm,znakmalyo,znakmalyx,zmianapola,bootload,1,ruch,temporary);
                                }

                                if((mms.x>=600&&mms.x<=780)&&(mms.y>=370&&mms.y<=450))
                                {
                                    cout<<"Restart"<<endl;
                                     tresc9="";
                                     tekst9.setString(tresc9);
                                     for(int i=0;i<9;i++)
                                     {
                                         tabactive[i]=-1;
                                     }
                                     blockclick=false;
                                     chplayerclicked=kopiaplayerclicked;
                                    showCharm(chplayerclicked,spriteznakm,znakmalyo,znakmalyx,zmianapola,bootload,0,ruch,temporary);

                                    if(chplayerclicked==1)
                                        {
                                            cout<<"Zaczyna krzyżyk!"<<endl;
                                            bootload=true;
                                            botstart=true;
                                        }
                                    temporary=1;
                                    przywroctemp=0;
                                    ruch=0;
                                    tresc12="";
                                    tekst12.setString(tresc12);
                                    short int ruch1=-1;
                                    short int ruch2=-1;
                                    sekwkolko=false;
                                }

                                if((mms.x>=600&&mms.x<=780)&&(mms.y>=470&&mms.y<=550))
                                {
                                     tresc9="";
                                     tekst9.setString(tresc9);
                                     for(int i=0;i<9;i++)
                                     {
                                         tabactive[i]=-1;
                                     }
                                     blockclick=false;
                                     temporary=1;
                                     przywroctemp=0;
                                     ruch=0;
                                     tryb=0;
                                     chplayerclicked=kopiaplayerclicked;
                                    tresc12="";
                                    tekst12.setString(tresc12);
                                    short int ruch1=-1;
                                    short int ruch2=-1;
                                    sekwkolko=false;

                                     //@
                                }


                            }
                            }
                        break;
                        }
            }
        }




        for(int x=0;x<4;x++)
        {

            for(int y=0;y<3;y++)
            {
                spritetlo.setPosition(x*200,y*200);
                Window.draw(spritetlo);
            }
        }

    //float ile=tekst14.getLocalBounds().width;
//cout<<ile<<endl;
        if(tryb==0)
        {
        Window.draw(chtryb);
        Window.draw(chplayer);
        Window.draw(chplayer2);
        Window.draw(Button01);
        Window.draw(Button02);

        Window.draw(tekst1);
        Window.draw(tekst2);
        Window.draw(tekst3);
        Window.draw(tekst4);
        Window.draw(tekst5);
        Window.draw(tekst6);
        Window.draw(tekst7);
        Window.draw(tekst8);
        Window.draw(tekst9);
        }
        else if(tryb==1)
        {


        Window.draw(Box1);
        Window.draw(Box2);
        Window.draw(Box3);
        Window.draw(Box4);
        Window.draw(Box5);
        Window.draw(Box6);
        Window.draw(Box7);
        Window.draw(Box8);
        Window.draw(Box9);


if(bootload==true&&temporary==1)
{
    cout<<"OPEN BOOT"<<endl;

   if(kopiaplayerclicked==0&&ruch==1)
    {
        cout<<"To jest ruch0 "<<ruch<<endl;
        cout<<"Ruch kompa po kółku"<<endl;
        for(int a=0;a<=8;a++)
        {
            if(tabactive[a]!=-1)
            {
            ruch1=a;
            break;
            }
        }
        if(ruch1==4)
        {
            temporary=100;
        }
        else if(ruch1==0||ruch1==2||ruch1==6||ruch1==8)
        {
            temporary=101;
            przywroctemp=101;
            sekwkolko=true;
        }
        else if(ruch1==1||ruch1==3||ruch1==5||ruch1==7)
        {
            temporary=102;
            przywroctemp=102;
            sekwkolko=true;
        }

    }
    else if(botstart==false&&sekwkolko==false)
    {
       temporary=100;
    }

    if(przywroctemp!=0)
    {
        temporary=przywroctemp;
    }

        if(temporary==101)
        {
            cout<<"Kółko zaczyna opcja 3"<<endl;
            cout<<"Ruch: "<<ruch<<endl;
            if(ruch==1)
            {
            tabactive[4]=chplayerclicked;
            chplayerclicked=!chplayerclicked;
            showCharm(chplayerclicked,spriteznakm,znakmalyo,znakmalyx,zmianapola,bootload,0,ruch,temporary);
            }
            else if(ruch==2)
            {
                for(int a=0;a<=8;a++)
                {
                    if(tabactive[a]==0&&a!=ruch1)
                    {
                    ruch2=a;
                    break;
                    }
                }

            if((ruch1==0&&(ruch2==5||ruch2==7||ruch2==8))||
               (ruch1==2&&(ruch2==3||ruch2==6||ruch2==7))||
               (ruch1==6&&(ruch2==1||ruch2==2||ruch2==5))||
               (ruch1==8&&(ruch2==0||ruch2==1||ruch2==3)))
            {
                    cout<<"Nie w lini"<<endl;
                    short int where=-1;
                    where=chopposite(tabactive,1,2);
                    if(where==-1)
                    {
                        where=chopposite(tabactive,3,2);
                    }
                    tabactive[where]=chplayerclicked;
                    chplayerclicked=!chplayerclicked;
                    showCharm(chplayerclicked,spriteznakm,znakmalyo,znakmalyx,zmianapola,bootload,0,ruch,temporary);
                    przywroctemp=100;
                    sekwkolko=false;
            }
            else
            {
                cout<<"W lini"<<endl;
                temporary=100;
                przywroctemp=100;
                sekwkolko=false;
            }
            }


        }
        else if(temporary==102)
        {
            if(ruch==1)
            {
            tabactive[4]=chplayerclicked;
            chplayerclicked=!chplayerclicked;
            showCharm(chplayerclicked,spriteznakm,znakmalyo,znakmalyx,zmianapola,bootload,0,ruch,temporary);
            }
            else if(ruch==2)
            {
                for(int a=0;a<=8;a++)
                {
                    if(tabactive[a]==0&&a!=ruch1)
                    {
                    ruch2=a;
                    break;
                    }
                }

            if((ruch1==1&&(ruch2==3||ruch2==5||ruch2==6||ruch2==8))||
               (ruch1==3&&(ruch2==1||ruch2==2||ruch2==7||ruch2==8))||
               (ruch1==5&&(ruch2==0||ruch2==1||ruch2==6||ruch2==7))||
               (ruch1==7&&(ruch2==0||ruch2==2||ruch2==3||ruch2==5)))
            {
                    cout<<"Nie w lini"<<endl;
                    short int where=-1;
                    where=chopposite(tabactive,1,2);
                    if(where==-1)
                    {
                        where=chopposite(tabactive,3,2);
                        if(where==-1)
                        {
                            //tutaj wybrac sekwencje
                            where=chopposite(tabactive,0,3);
                            if(where==-1)
                            {
                                where=chopposite(tabactive,2,3);
                            }
                        }
                    }
                    tabactive[where]=chplayerclicked;
                    chplayerclicked=!chplayerclicked;
                    showCharm(chplayerclicked,spriteznakm,znakmalyo,znakmalyx,zmianapola,bootload,0,ruch,temporary);
                    przywroctemp=100;
                    sekwkolko=false;
            }
            else
            {
                cout<<"W lini"<<endl;
                temporary=100;
                przywroctemp=100;
                sekwkolko=false;
            }

        }
        }

        if(temporary==100)
        {
            cout<<"Giwbi"<<endl;
            short int where=-1;
            where=atakiobrona(tabactive,where);

            if(where==-1)
            {
            where=chopposite(tabactive,0,3); // 0 to tam gdzie jestes spr czy mozna tu wykonac ruch

            if(where==-1)
            {
                cout<<"Wywołanie!"<<endl;
                where=chopposite(tabactive,2,3);//CZESC DALSZA NASTAPI
                if(where==-1)
                {
                    where=chopposite(tabactive,3,2);
                    if(where==-1)
                    {
                        where=chopposite(tabactive,7,2);
                        if(where==-1)
                        {
                            cout<<"Brak mozliwosci wygranej"<<endl;
                        }
                    }
                }
            }
            }
            if(where!=-1)
            {
            tabactive[where]=chplayerclicked;
            chplayerclicked=!chplayerclicked;
            showCharm(chplayerclicked,spriteznakm,znakmalyo,znakmalyx,zmianapola,bootload,0,ruch,temporary);
            }
            else
            {
                cout<<"Brak opcji!"<<endl;
                 for(int y=0;y<=8;y++)
                {
                    if(tabactive[y]==-1)
                    {
                        tabactive[y]=chplayerclicked;
                        break;
                    }
                }
                chplayerclicked=!chplayerclicked;
                showCharm(chplayerclicked,spriteznakm,znakmalyo,znakmalyx,zmianapola,bootload,0,ruch,temporary);
            }
            //Koniec spr



        }

        if(botstart==true)
        {
            tabactive[4]=chplayerclicked;
            chplayerclicked=!chplayerclicked;
            showCharm(chplayerclicked,spriteznakm,znakmalyo,znakmalyx,zmianapola,bootload,0,ruch,temporary);
            temporary=100;
            botstart=false;
        }
        //Ruch 1 po x


    bootload=false;
}
        for(int i=0;i<9;i++)
        {

            if(tabactive[i]!=-1)
            {

                if(tabactive[i]==0)
                {
                    spriteznak.setTexture(znako);
                }
                else if(tabactive[i]==1)
                {
                    spriteznak.setTexture(znakx);
                }

                switch(i)
                {
                case 0:
                    {
                    spriteznak.setPosition(57,50);
                    Window.draw(spriteznak);
                    break;
                    }
                case 1:
                    {
                    spriteznak.setPosition(207,50);
                    Window.draw(spriteznak);
                    break;
                    }
                case 2:
                    {
                    spriteznak.setPosition(357,50);
                    Window.draw(spriteznak);
                    break;
                    }
                case 3:
                    {
                    spriteznak.setPosition(57,200);
                    Window.draw(spriteznak);
                    break;
                    }
                case 4:
                    {
                    spriteznak.setPosition(207,200);
                    Window.draw(spriteznak);
                    break;
                    }
                case 5:
                    {
                    spriteznak.setPosition(357,200);
                    Window.draw(spriteznak);
                    break;
                    }
                case 6:
                    {
                    spriteznak.setPosition(57,350);
                    Window.draw(spriteznak);
                    break;
                    }
                case 7:
                    {
                    spriteznak.setPosition(207,350);
                    Window.draw(spriteznak);
                    break;
                    }
                case 8:
                    {
                    spriteznak.setPosition(357,350);
                    Window.draw(spriteznak);
                    break;
                    }


                }
            }
        }
            if(zmianapola==true)
            {
                for(int i=0;i<2;i++)
                {


                if((tabactive[0]==i&&tabactive[1]==i&&tabactive[2]==i)||
                   (tabactive[3]==i&&tabactive[4]==i&&tabactive[5]==i)||
                   (tabactive[6]==i&&tabactive[7]==i&&tabactive[8]==i)||
                   (tabactive[0]==i&&tabactive[3]==i&&tabactive[6]==i)||
                   (tabactive[1]==i&&tabactive[4]==i&&tabactive[7]==i)||
                   (tabactive[2]==i&&tabactive[5]==i&&tabactive[8]==i)||
                   (tabactive[0]==i&&tabactive[4]==i&&tabactive[8]==i)||
                   (tabactive[2]==i&&tabactive[4]==i&&tabactive[6]==i))
                   {
                        if(i==0)
                        {
                          tresc12=L"Wygrywa Kółko!" ;
                          tekst12.setString(tresc12);
                          blockclick=true;

                        }
                        else if(i==1)
                        {
                           tresc12=L"Wygrywa Krzyżyk!" ;
                           tekst12.setString(tresc12);
                           blockclick=true;

                        }
                   }
                }
            zmianapola=false;
            bool checkifend=true;
            for(int y=0;y<=8;y++)
            {
               if(tabactive[y]==-1)
               {
                   checkifend=false;
               }
            }
            if(checkifend==true&&blockclick==false)
            {
                tresc12=L"Remis!" ;
                tekst12.setString(tresc12);
                blockclick=true;
            }
            }
        //Po zrenderowaniu kika czy jest zwyciezca oraz czy jest jeszcze miejsce na planszy

        Window.draw(spriteznakm);

        Window.draw(Button11);
        Window.draw(Button12);

        Window.draw(tekst11);
        Window.draw(tekst12);
        Window.draw(tekst13);
        Window.draw(tekst14);

        }


        Window.display();
        Window.clear();
    }


    return 0;
}

void showCharm(const bool &chplayerclicked,sf::Sprite &spriteznakm,const sf::Texture &znakmalyo,const sf::Texture &znakmalyx,bool &zmianapola,bool &bootload,short int rodzaj,short int &ruch,short int &temporary)
{
    if(chplayerclicked==0)
    {
        spriteznakm.setTexture(znakmalyo);
    }

    if(chplayerclicked==1)
    {
        spriteznakm.setTexture(znakmalyx);
    }

    if(rodzaj==1)
    {
        bootload=true;
        temporary=1;
        ruch++;
    }
    zmianapola=1;
}
short int chopposite(const int tabactive[],short int nr,short int priority)
{
    //zworci pusta liczbe jak nie ma przeciwnych -1
    //zworci przeciwna
short int gotnumber=-1;


    if((nr==0||nr==8)&&priority==3)
    {
        //spr dodatkowo dla 0 opcje kombinacji
      if(((tabactive[1]==0&&tabactive[2]==-1)||(tabactive[2]==0&&tabactive[1]==-1))&&
         ((tabactive[3]==0&&tabactive[6]==-1)||(tabactive[6]==0&&tabactive[3]==-1))&&nr==0)
      {
          gotnumber=0;
      }
      else if(((tabactive[6]==0&&tabactive[7]==-1)||(tabactive[7]==0&&tabactive[6]==-1))&&
         ((tabactive[2]==0&&tabactive[5]==-1)||(tabactive[5]==0&&tabactive[2]==-1))&&nr==8)
      {
          gotnumber=8;
      }
      else
      {
        if(tabactive[0]==-1&&tabactive[8]==-1&&nr!=0)
        {
            gotnumber=0;

        }
        else if(tabactive[8]==-1&&tabactive[0]==-1&&nr!=8)
        {
            gotnumber=8;

        }
      }

    }

    if((nr==6||nr==2)&&priority==3)
    {
      if(((tabactive[0]==0&&tabactive[1]==-1)||(tabactive[1]==0&&tabactive[0]==-1))&&
         ((tabactive[8]==0&&tabactive[5]==-1)||(tabactive[5]==0&&tabactive[8]==-1))&&nr==2)
      {
          gotnumber=2;
      }
      else if(((tabactive[7]==0&&tabactive[8]==-1)||(tabactive[8]==0&&tabactive[7]==-1))&&
         ((tabactive[0]==0&&tabactive[3]==-1)||(tabactive[3]==0&&tabactive[0]==-1))&&nr==6)
      {
          gotnumber=6;
      }
      else
      {

        if(tabactive[2]==-1&&tabactive[6]==-1&&nr!=2)
        {
            gotnumber=2;

        }
        else if(tabactive[6]==-1&&tabactive[2]==-1&&nr!=6)
        {
            gotnumber=6;

        }
      }



    }

    if((nr==1||nr==7)&&priority==2)
    {
        if(tabactive[1]==-1&&tabactive[7]==-1&&nr!=1)
        {
            gotnumber=1;
        }
        else if(tabactive[7]==-1&&tabactive[1]==-1&&nr!=7)
        {
            gotnumber=7;
        }
    }

    if((nr==3||nr==5)&&priority==2)
    {
        if(tabactive[3]==-1&&tabactive[5]==-1&&nr!=3)
        {
            gotnumber=3;
        }
        else if(tabactive[5]==-1&&tabactive[3]==-1&&nr!=5)
        {
            gotnumber=5;
        }
    }
return gotnumber;

}
short int atakiobrona(int tabactive[],short int &where)
{
  for(int z=1;z>=0;z--)
            {
            if(tabactive[0]==z&&tabactive[1]==z&&tabactive[2]==-1)
                where=2;
            else if(tabactive[1]==z&&tabactive[2]==z&&tabactive[0]==-1)
                where=0;
            else if(tabactive[0]==z&&tabactive[2]==z&&tabactive[1]==-1)
                where=1;

            else if(tabactive[3]==z&&tabactive[4]==z&&tabactive[5]==-1)
                where=5;
            else if(tabactive[4]==z&&tabactive[5]==z&&tabactive[3]==-1)
                where=3;
            else if(tabactive[3]==z&&tabactive[5]==z&&tabactive[4]==-1)
                where=4;

            else if(tabactive[6]==z&&tabactive[7]==z&&tabactive[8]==-1)
                where=8;
            else if(tabactive[7]==z&&tabactive[8]==z&&tabactive[6]==-1)
                where=6;
            else if(tabactive[6]==z&&tabactive[8]==z&&tabactive[7]==-1)
                where=7;

            else if(tabactive[0]==z&&tabactive[3]==z&&tabactive[6]==-1)
                where=6;
            else if(tabactive[3]==z&&tabactive[6]==z&&tabactive[0]==-1)
                where=0;
            else if(tabactive[0]==z&&tabactive[6]==z&&tabactive[3]==-1)
                where=3;

            else if(tabactive[1]==z&&tabactive[4]==z&&tabactive[7]==-1)
                where=7;
            else if(tabactive[4]==z&&tabactive[7]==z&&tabactive[1]==-1)
                where=1;
            else if(tabactive[1]==z&&tabactive[7]==z&&tabactive[4]==-1)
                where=4;

            else if(tabactive[2]==z&&tabactive[5]==z&&tabactive[8]==-1)
                where=8;
            else if(tabactive[5]==z&&tabactive[8]==z&&tabactive[2]==-1)
                where=2;
            else if(tabactive[2]==z&&tabactive[8]==z&&tabactive[5]==-1)
                where=5;

            else if(tabactive[0]==z&&tabactive[4]==z&&tabactive[8]==-1)
                where=8;
            else if(tabactive[4]==z&&tabactive[8]==z&&tabactive[0]==-1)
                where=0;
            else if(tabactive[0]==z&&tabactive[8]==z&&tabactive[4]==-1)
                where=4;

            else if(tabactive[2]==z&&tabactive[4]==z&&tabactive[6]==-1)
                where=6;
            else if(tabactive[4]==z&&tabactive[6]==z&&tabactive[2]==-1)
                where=2;
            else if(tabactive[2]==z&&tabactive[6]==z&&tabactive[4]==-1)
                where=4;

                if(where!=-1)
                {
                    z=-1;
                }
            }
    return where;
}
