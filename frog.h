#ifndef FROG_H
#define FROG_H
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"
#include <SFML/Window.hpp>

class Frog
{
    short x;

    unsigned short y;

    sf::Sprite sprite;

    sf::Texture texture;

    bool control_keys[4];

public:
    Frog();
    void draw(sf::RenderWindow& i_window);
    void update();
};

#endif // FROG_H
