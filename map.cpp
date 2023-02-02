#include <SFML/Graphics.hpp>
#include <Global.h>
#include <math.h>
#include "map.h"

void Map::draw_map(sf::RenderWindow& window)
{
    sf::RectangleShape cell_shape(sf::Vector2f(CELL_SIZE,CELL_SIZE));


//    for(int y = 0 * CELL_SIZE; y < MAP_HEIGHT*CELL_SIZE*SCREEN_RESIZE + CELL_SIZE; y++)
//    {
//        for(int x = 0 * CELL_SIZE; x < MAP_HEIGHT*CELL_SIZE*SCREEN_RESIZE + CELL_SIZE; x++)
//        {
//            if(y > 1 * CELL_SIZE || y < MAP_HEIGHT - 1) // WATER
//            {
//                cell_shape.setFillColor(sf::Color(0, 76, 153));
//                cell_shape.setPosition(sf::Vector2f(x,y));
//                window.draw(cell_shape);
//            }
//            else if(y < 1 * CELL_SIZE || y == MAP_HEIGHT) //GROUND
//            {
//                cell_shape.setFillColor(sf::Color(0, 204, 102));
//                cell_shape.setPosition(sf::Vector2f(x,y));
//                window.draw(cell_shape);
//            }

//        }
//    }

    for(int y = 0; y < MAP_HEIGHT*SCREEN_RESIZE + 2; y++)
    {
        for(int x = 0; x < MAP_WIDTH*SCREEN_RESIZE; x++)
        {

                if(y < 2)
                {
                    cell_shape.setFillColor(sf::Color(0, 204, 102));
                    cell_shape.setPosition(sf::Vector2f(CELL_SIZE * x , CELL_SIZE * y));
                    window.draw(cell_shape);
                }
                else if(y == 2) // Swamp area
                {

                        if(x % 4 == 0 || x == 31)
                        {
                            cell_shape.setFillColor(sf::Color(0, 204, 102));
                            cell_shape.setPosition(sf::Vector2f(CELL_SIZE * x, CELL_SIZE * y));
                            window.draw(cell_shape);
                        }

                        else
                        {
                            cell_shape.setFillColor(sf::Color(0, 76, 153));
                            cell_shape.setPosition(sf::Vector2f(CELL_SIZE * x, CELL_SIZE * y));
                            window.draw(cell_shape);
                        }



                }
                else if(y < MAP_HEIGHT*SCREEN_RESIZE/2)
                {
                cell_shape.setFillColor(sf::Color(0, 76, 153));
                cell_shape.setPosition(sf::Vector2f(CELL_SIZE * x , CELL_SIZE * y));
                window.draw(cell_shape);
                }
                else if(y > MAP_HEIGHT*SCREEN_RESIZE - 1)
                {
                    cell_shape.setFillColor(sf::Color(224, 224, 224));
                    cell_shape.setPosition(sf::Vector2f(CELL_SIZE * x , CELL_SIZE * y));
                    window.draw(cell_shape);
                }
                else
                {
                    cell_shape.setFillColor(sf::Color::Black);
                    cell_shape.setPosition(sf::Vector2f(CELL_SIZE * x , CELL_SIZE * y));
                    window.draw(cell_shape);
                }


        }
    }


}
