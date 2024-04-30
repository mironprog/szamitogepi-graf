#include <stdio.h>
#include <SDL2/SDL.h>
#include <time.h>
#include <GL/gl.h>

#include "constants.h"
#include "window.h"
#include "ship.h"
#include "ship.c"
#include "missile.h"
#include "missile.c"

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

void process_input(App* app, Ship* ship, Missile* missile)
{
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_KEYDOWN:
            switch (event.key.keysym.scancode) {
                case SDL_SCANCODE_ESCAPE:
                    app->game_is_running = FALSE;
                    break;
                case SDL_SCANCODE_W:
                    move_ship_y_axis(ship, -10);
                    break;
                case SDL_SCANCODE_S:
                    move_ship_y_axis(ship, 10);
                    break;
                case SDL_SCANCODE_A:
                    move_ship_x_axis(ship, -10);
                    break;
                case SDL_SCANCODE_D:
                    move_ship_x_axis(ship, 10);
                    break;
                case SDL_SCANCODE_E:
                    move_ship_x_axis(ship, 10);
                    move_ship_y_axis(ship, -10);
                    break;
                case SDL_SCANCODE_Q:
                    move_ship_x_axis(ship, -10);
                    move_ship_y_axis(ship, -10);
                    break;
                case SDL_SCANCODE_SPACE:
                    update_missile(missile, 0.1);
                    break;
                default:
                    break;
            }
            break;
        /*
        case SDL_KEYUP:
            switch (event.key.keysym.scancode) {
            //case SDL_SCANCODE_W:
            //case SDL_SCANCODE_S:
            case SDL_SCANCODE_SPACE:
                
                break;
            case SDL_SCANCODE_A:
            case SDL_SCANCODE_D:
                //move_ship_y_axis(ship, 0);
                break;
            default:
                break;
            }
            break;*/
        }
    }
}
     

void setup(Ship* ship, Missile* missile)
{
    init_ship(ship, 400, 550, 20, 20);
    init_missile(missile, 400, 550, 10, 40, 600);
}

void update(Missile* missile)
{
    int last_frame_time = 0;
    while (!SDL_TICKS_PASSED(SDL_GetTicks(), last_frame_time + FRAME_TARGET_TIME));

    float delta_time = (SDL_GetTicks() - last_frame_time) / 1100000.0f;

    last_frame_time = SDL_GetTicks();

    printf("%.3f", delta_time);
    update_missile(missile, delta_time);

    
}

void renderer(App* app, Ship* ship, Missile* missile)
{
    SDL_SetRenderDrawColor(app->renderer, 0, 0, 0, 255);
    SDL_RenderClear(app->renderer);

    SDL_Rect ship_rect = { 
        (int)ship->x, 
        (int)ship->y, 
        (int)ship->width, 
        (int)ship->height
        };
    
    SDL_Rect missile_rect = {
        (int)missile->x,
        (int)missile->y,
        (int)missile->width,
        (int)missile->height
        };
    
    SDL_SetRenderDrawColor(app->renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(app->renderer, &ship_rect);
    SDL_RenderFillRect(app->renderer, &missile_rect);

    
    

    SDL_RenderPresent(app->renderer);
}