#ifndef MISSILE_H
#define MISSILE_H

typedef struct Missile
{
    float x;
    float y;
    float width;
    float height;
    float limit;
    float radius;
    float speed_x;
    float speed_y;
} Missile;

/**
 * Update the missile.
 * @param time elapsed time in seconds.
 */
void update_missile(Missile* missile, float position);



#endif