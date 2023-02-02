#include "frog.h"
#include <QCoreApplication>
#include <SFML/Graphics.hpp>
#include <Global.h>
#include "map.h"
#include <chrono>

int main()
{
sf::RenderWindow myWindow;
myWindow.create(sf::VideoMode(CELL_SIZE * MAP_WIDTH * SCREEN_RESIZE, SCREEN_RESIZE * CELL_SIZE * MAP_HEIGHT + CELL_SIZE), "Frogger");
myWindow.display();
myWindow.clear();
sf::Event myEventHandler;
//myWindow.clear(sf::Color(0, 76, 0));

//Time stuff
std::chrono::microseconds lag(0);

std::chrono::steady_clock::time_point previous_time;
previous_time = std::chrono::steady_clock::now();

//Mr frog :)
Frog frog;

Map map;

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
//


    map.draw_map(myWindow);
    frog.draw(myWindow);
    frog.update();
    myWindow.display();
}
}
