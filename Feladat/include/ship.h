#ifndef SHIP_H
#define SHIP_H


typedef struct Ship
{
    float x;
    float y;
    float width;
    float height;
}Ship;

void init_ship(Ship* ship, float x, float y, float width, float height);

void move_ship_x_axis(Ship* ship, float scale);

void move_ship_y_axis(Ship* ship, float scale);

void attack(Ship* ship);

#endif /* SHIP_H */