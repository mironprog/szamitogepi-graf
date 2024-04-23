#ifndef APP_H
#define APP_H

#include <SDL2/SDL.h>
#include <stdbool.h>

typedef struct App
{
    SDL_Window* window;
    SDL_Renderer* renderer;
    bool game_is_running; 
} App;

int initialize_window(App* app);

void setup();

void process_input(App* app);

void update();

void renderer();

void destroy_window(App* app);

#endif