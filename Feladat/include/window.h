#ifndef APP_H
#define APP_H

#include <SDL2/SDL.h>
#include <stdbool.h>
#include "ship.h"
#include "missile.h"

typedef struct App
{
    SDL_Window* window;
    SDL_Renderer* renderer;
    bool game_is_running; 
} App;

int initialize_window(App* app);

void setup(Ship* ship, Missile* missile);

void process_input(App* app, Ship* ship, Missile* missile);

void update(Missile* missile);

void renderer();

void destroy_window(App* app);

#endif