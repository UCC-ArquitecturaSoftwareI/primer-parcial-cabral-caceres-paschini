#include <raylib.h>
#include "clases/Game/Game.h"
#include "clases/Menu/Menu.h"
#include "clases/Ending/Ending.h"
#include "clases/State/Context.h"
#include "clases/State/Handle.h"


#if defined(PLATFORM_WEB) // Para crear HTML5
#include <emscripten/emscripten.h>
#endif


int main() {
    InitWindow(1104, 688, "hola");
    InitAudioDevice();

#if defined(PLATFORM_WEB)  // Para versión Web.
#else
    SetTargetFPS(60);   // Set our game to run at 60 frames-per-second
    // Main loop
    Context Cont{};
    Handle Hand;
    bool Won;
    Vector2 Time = {0, 0};
    int Sta =0;
    Game &game = Game::Get_Game();
    Cont.SetCurrentState(&Hand);
    while (Sta != 4) {
        switch (Sta) {
            case 0:
                Cont.Start_State();
                Sta = Cont.Stop_State();
                break;
            case 1: {
                Menu Men;
                Cont.SetCurrentState(&Men);
                Cont.Start_State();
                Sta = Cont.Stop_State();
                break;
            }
            case 2: {

                Cont.SetCurrentState(&game);
                Cont.Start_State();
                Won = game.GetWon();
                Time = game.GetTime();
                Sta = Cont.Stop_State();
                break;
            }
            case 3: {
                Ending End;
                End.LoadState(Won, Time);
                Cont.SetCurrentState(&End);
                Cont.Start_State();
                Sta = Cont.Stop_State();
                break;
            }
        }
    }


#endif
    return 0;
}