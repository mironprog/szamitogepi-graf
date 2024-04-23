#include <stdio.h>
#include <SDL2/SDL.h>
#include "window.h"

int main(int argc, char* argv[])
{

    App app;
    app.game_is_running = initialize_window(&app);

    setup();

    while(app.game_is_running){
        process_input(&app);
        update();
        renderer();
    }

    destroy_window(&app);

    return 0;
}