#include <raylib.h>
#include "clases/Game/Game.h"
#include "clases/Menu/Menu.h"



#if defined(PLATFORM_WEB) // Para crear HTML5
#include <emscripten/emscripten.h>
#endif


int main() {

    Game &game = Game::Get_Game();

#if defined(PLATFORM_WEB)  // Para versión Web.
    emscripten_set_main_loop(UpdateDrawFrame, 0, 1);
#else
    SetTargetFPS(60);   // Set our game to run at 60 frames-per-second
    // Main loop

    //Menu Men;
    game.Update_Game();

#endif
    // Descargar todos los resources cargados
    game.EndGame();
    //Men.Draw();
    return 0;
}
