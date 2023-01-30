#include "frog.h"
#include "Global.h"
#include <chrono>
#include <cmath>
#include <SFML/Window/Keyboard.hpp>

Frog::Frog()
{
    x = (CELL_SIZE * floor(0.5f * MAP_WIDTH));
    y = (CELL_SIZE * (MAP_HEIGHT -1));

    texture.loadFromFile("assets/frog.png");

    sprite.setTexture(texture);

}

void Frog::draw(sf::RenderWindow& i_window)
{

    sprite.setPosition(x, y);

    i_window.draw(sprite);
}
void Frog::update()
{
    if(0 == control_keys[0] && 1 == sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        x = std::min(CELL_SIZE + x, CELL_SIZE * (MAP_WIDTH -1));
    }
    if(0 == control_keys[1] && 1 == sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        y = std::max(y - CELL_SIZE, 0);
    }
    if(0 == control_keys[2] && 1 == sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        x = std::max(x - CELL_SIZE, 0);
    }
    if(0 == control_keys[3] && 1 == sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        y = std::min(CELL_SIZE + y, CELL_SIZE * (MAP_HEIGHT -1));
    }

    control_keys[0] = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
    control_keys[1] = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
    control_keys[2] = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
    control_keys[3] = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);

}
