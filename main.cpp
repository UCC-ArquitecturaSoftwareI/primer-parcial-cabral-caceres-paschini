#include <raylib.h>
#include "clases/Game/Game.h"
#include "clases/Menu/Menu.h"
#include "clases/Ending/Ending.h"


#if defined(PLATFORM_WEB) // Para crear HTML5
#include <emscripten/emscripten.h>
#endif


int main() {


#if defined(PLATFORM_WEB)  // Para versión Web.
    emscripten_set_main_loop(UpdateDrawFrame, 0, 1);
#else
    SetTargetFPS(60);   // Set our game to run at 60 frames-per-second
    // Main loop
    Menu Men;
    Men.Update_Menu();
    Game &game = Game::Get_Game();
    game.PlayMusic();
    game.Update_Game();
    game.EndGame();
    Ending End;

#endif
    // Descargar todos los resources cargados

    //End.Draw();
    return 0;
}