#include <stdio.h>
#include <SDL2/SDL.h>
#include "constants.h"
#include "window.h"



int initialize_window(App* app)
{
    app->game_is_running = FALSE;
    app->window = NULL;
    app->renderer = NULL;

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        fprintf(stderr, "Error initializing SDL.\n");
        return FALSE;
    }
    app->window = SDL_CreateWindow(
        "Mygame",
        SDL_WINDOWPOS_CENTERED, 
        SDL_WINDOWPOS_CENTERED,
        WINDOW_WIDTH, 
        WINDOW_HEIGHT,
        SDL_WINDOW_OPENGL
        );
        if (!app->window) {
            fprintf(stderr, "Error creating SDL Window.\n");
            return FALSE;
        }
        app->renderer = SDL_CreateRenderer(app->window, -1, 0);
        if (!app->renderer) {
            fprintf(stderr, "Error creating SDL Renderer.\n");
            return FALSE;
        }

    return TRUE;
}

void destroy_window(App* app)
{
    SDL_DestroyRenderer(app->renderer);
    SDL_DestroyWindow(app->window);
    SDL_Quit();
}

void process_input(App* app)
{
    SDL_Event event;
    SDL_PollEvent(&event);

    switch(event.type) {
        case SDL_QUIT:
            app->game_is_running =  FALSE;
            break;
        case SDL_KEYDOWN:
            if(event.key.keysym.sym == SDLK_ESCAPE)
                app->game_is_running = FALSE;
            break;
    }
}

void setup()
{

}

void update()
{

}

void renderer()
{

}