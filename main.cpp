#include <raylib.h>

#include "clases/Personaje/Player.h"
#include "clases/Map/Map.h"
#include "clases/Renderer/Renderer.h"
#include "clases/Music Renderer/Sound_Render.h"
#include "clases/Game/Game.h"


#if defined(PLATFORM_WEB) // Para crear HTML5
#include <emscripten/emscripten.h>
#endif
const int screenWidth = 640*1.2;
const int screenHeight = 480*1.2;




int main() {

    //Inicialización de la ventana
    InitWindow(screenWidth, screenHeight, "raylib - Plataformer");
    InitAudioDevice();

    Game *game;
    game = new Game();


    game->PlayMusic();


#if defined(PLATFORM_WEB)  // Para versión Web.
    emscripten_set_main_loop(UpdateDrawFrame, 0, 1);
#else
    SetTargetFPS(60);   // Set our game to run at 60 frames-per-second
    // Main loop
    while (!WindowShouldClose()) {
        game->UpdateFrame();
        game->UpdateMusic();
    }
#endif


    // Descargar todos los resources cargados

    //UnloadMusicStream(Srend.getMusic());   // Descargo la musica de RAM
    CloseAudioDevice();         // Cierro el dispositivo de Audio
    CloseWindow();              // Cierro la ventana
    return 0;
}





/**
 *  Función dedicada a dibujar cada frame. Acá adentro se debe poner la logica necesaria para representar un nuevo frame
 *  del juego.
 */
