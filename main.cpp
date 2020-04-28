#include <raylib.h>

#include "clases/Personaje/Player.h"
#include "clases/Map/Map.h"
#include "clases/Renderer/Renderer.h"
#include "clases/Music Renderer/Sound_Render.h"

#if defined(PLATFORM_WEB) // Para crear HTML5
#include <emscripten/emscripten.h>
#endif
const int screenWidth = 1536;
const int screenHeight = 864;


// Variables Globales
Map *map;
Player *player;
//Sound_Render *Srend;


int main() {

    map = new Map("resources/Level/Map.json");
    player = new Player("resources/Player/spritesheet.png", map->ReturnCharPos());

    Renderer Rend(map, player);
    // Srend = new Sound_Render("resources/Music/Song.mp3");

    // Inicialización de la ventana
    InitWindow(screenWidth, screenHeight, "raylib - Plataformer");
    InitAudioDevice();              // Initialize audio device

    /// Ejemplo de utilización de audio.

    //Srend->PlayMusic();


#if defined(PLATFORM_WEB)  // Para versión Web.
    emscripten_set_main_loop(UpdateDrawFrame, 0, 1);
#else
    SetTargetFPS(60);   // Set our game to run at 60 frames-per-second
    // Main loop
    while (!WindowShouldClose()) {
        Rend.UpdateDrawFrame();
        //Srend->UpdateMusic();
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
