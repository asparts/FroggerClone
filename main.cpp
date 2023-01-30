#include "frog.h"
#include <QCoreApplication>
#include <SFML/Graphics.hpp>
#include <Global.h>

#include <chrono>

int main()
{
QCoreApplication a();
sf::RenderWindow myWindow(sf::VideoMode(CELL_SIZE * MAP_WIDTH * SCREEN_RESIZE, SCREEN_RESIZE * (FONT_HEIGHT + CELL_SIZE * MAP_HEIGHT)), "Frogger", sf::Style::Close);
sf::Event myEventHandler;


//Time stuff
std::chrono::microseconds lag(0);

std::chrono::steady_clock::time_point previous_time;
previous_time = std::chrono::steady_clock::now();

//Mr frog :)
Frog frog;

while(myWindow.isOpen())
{

    if(myWindow.pollEvent(myEventHandler))
    {
        if(myEventHandler.type == sf::Event::Closed)
        {
            myWindow.close();
            return 0;
        }
    }


    std::chrono::microseconds delta_time = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - previous_time);
    lag += delta_time;
    previous_time += delta_time;

//    myWindow.clear(sf::Color(255,0,0));
//    myWindow.display();

    myWindow.clear(sf::Color(0,0,255));
    frog.draw(myWindow);
}
}
