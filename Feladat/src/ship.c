#include "ship.h"



void init_ship(Ship* ship, float x, float y, float width, float height)
{
    ship->x = x;
    ship->y = y;
    ship->width = width;
    ship->height = height;
}

void move_ship_x_axis(Ship* ship, float scale)
{
    ship->x += scale;
}

void move_ship_y_axis(Ship* ship, float scale)
{
    ship->y += scale;
}