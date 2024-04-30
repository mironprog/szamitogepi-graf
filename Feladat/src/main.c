#include <stdio.h>
#include <SDL2/SDL.h>
#include "window.h"
#include "ship.h"
#include "missile.h"

int main(int argc, char* argv[])
{

    App app;
    Ship ship;
    Missile missile;
    app.game_is_running = initialize_window(&app);

    setup(&ship, &missile);

    while(app.game_is_running){
        process_input(&app, &ship, &missile);
        update(&missile);
        renderer(&app, &ship, &missile);
    }

    destroy_window(&app);

    return 0;
}