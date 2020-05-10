#include <raylib.h>
#include <physac.h>
#include "clases/Personaje/Enemigo.h"
#include "clases/Map/Map.h"

#if defined(PLATFORM_WEB) // Para crear HTML5
#include <emscripten/emscripten.h>
#endif
const int screenWidth = 864;
const int screenHeight = 576;

// Variables Globales
Music music;
Enemigo *player;
Mapa *mapa;
Camera2D camera={0};
static void UpdateDrawFrame(void);          // Función dedicada a operar cada frame

int main() {

    player = new Enemigo("resources/Enemigo/enemigo.png", mapa->player_init_pos);

    mapa = new   Mapa ("resources/level/aNivel3.json");
    // Inicialización de la ventana
    InitWindow(screenWidth, screenHeight, "raylib template - advance game");
    InitAudioDevice();              // Initialize audio device

    /// Ejemplo de utilización de audio.
    music = LoadMusicStream("resources/Cyberpunk Moonlight Sonata.mp3");

    PlayMusicStream(music);

   InitPhysics();
   PhysicsBody floor= CreatePhysicsBodyRectangle((Vector2){screenWidth/2,screenHeight},500, 100,10);
   floor->enabled=false;
   // PhysicsBody playerBody= CreatePhysicsBodyRectangle(player->getEnemigoPos(),45,30,10);//VERRRRRRRRR
   //Configuracion de la Camara
   camera.target={player->getEnemigoPos().x, player->getEnemigoPos().y -110}; //Numero magico
   camera.offset=(Vector2){screenWidth/2,screenHeight/2};
   camera.zoom=1.0f;

#if defined(PLATFORM_WEB)  // Para versión Web.
    emscripten_set_main_loop(UpdateDrawFrame, 0, 1);
#else
    SetTargetFPS(60);   // Set our game to run at 60 frames-per-second
    // Main loop
    while (!WindowShouldClose()) {
        UpdateDrawFrame();
    }
#endif


    // Descargar todos los resources cargados

    UnloadMusicStream(music);   // Descargo la musica de RAM
    CloseAudioDevice();         // Cierro el dispositivo de Audio
    CloseWindow();              // Cierro la ventana
    return 0;
}


/**
 *  Función dedicada a dibujar cada frame. Acá adentro se debe poner la logica necesaria para representar un nuevo frame
 *  del juego.
 */
static void UpdateDrawFrame(void) {

    // siempre hay que reproducir la musica que esta actualmente
    UpdateMusicStream(music);

    // Verifico Entradas de eventos.
    if (IsKeyDown(KEY_RIGHT)) {
        player->move_x(4);
        if (player->getEnemigoPos().x > camera.target.x + 200)
            camera.target.x = player->getEnemigoPos().x - 200;
    }
    if (IsKeyDown(KEY_LEFT)) {
        player->move_x(4);
        if (player->getEnemigoPos().x < camera.target.x - 200)
            camera.target.x = player->getEnemigoPos().x + 200;
    }
    if (IsKeyDown(KEY_UP)) player->move_y(-2.0f);
    if (IsKeyDown(KEY_DOWN)) player->move_y(2.0f);


    // Comienzo a dibujar
    BeginDrawing();
BeginMode2D(camera);
    {
        mapa->draw();
        player->draw();
    }
    ClearBackground(RAYWHITE); // Limpio la pantalla con blanco


    // Dibujo todos los elementos del juego.

    DrawText("Inicio", 10, 20, 30, LIGHTGRAY);

    // Finalizo el dibujado
    EndDrawing();
}