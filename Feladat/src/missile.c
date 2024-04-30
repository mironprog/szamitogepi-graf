#include "missile.h"

#include <GL/gl.h>

#include <math.h>


void init_missile(Missile* missile, float x, float y, float width, float  height, float table_height)
{
    missile->x = x;
    missile->y = y;
    missile->width = width;
    missile->height = height;
    missile->limit = table_height - missile->height;
    missile->radius = 50;
    missile->speed_x = 250;
    missile->speed_y = 250;
}

void update_missile(Missile* missile, float position)
{
    missile->y -= missile->speed_y * position; 
    
}


