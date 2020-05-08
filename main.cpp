#include <raylib.h>
/*
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
    //Srend = new Sound_Render("resources/Music/Song.mp3");

    //Inicialización de la ventana
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

*/

#include "raylib.h"

#define MAX_BUILDINGS   100

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - 2d camera");

    Rectangle player = { 400, 280, 40, 40 };
    Rectangle buildings[MAX_BUILDINGS] = { 0 };
    Color buildColors[MAX_BUILDINGS] = { 0 };

    int spacing = 0;

    for (int i = 0; i < MAX_BUILDINGS; i++)
    {
        buildings[i].width = GetRandomValue(50, 200);
        buildings[i].height = GetRandomValue(100, 800);
        buildings[i].y = screenHeight - 130 - buildings[i].height;
        buildings[i].x = -6000 + spacing;

        spacing += buildings[i].width;

        buildColors[i] = (Color){ static_cast<unsigned char>(GetRandomValue(200, 240)), static_cast<unsigned char>(GetRandomValue(200, 240)), static_cast<unsigned char>(GetRandomValue(200, 250)), 255 };
    }

    Camera2D camera = { 0 };
    camera.target = (Vector2){ player.x + 20, player.y + 20 };
    camera.offset = (Vector2){ screenWidth/2, screenHeight/2 };
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;

    SetTargetFPS(60);                   // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())        // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------

        // Player movement
        if (IsKeyDown(KEY_RIGHT)) player.x += 2;
        else if (IsKeyDown(KEY_LEFT)) player.x -= 2;

        // Camera target follows player
        camera.target = (Vector2){ player.x + 20, player.y + 20 };

        // Camera rotation controls
        if (IsKeyDown(KEY_A)) camera.rotation--;
        else if (IsKeyDown(KEY_S)) camera.rotation++;

        // Limit camera rotation to 80 degrees (-40 to 40)
        if (camera.rotation > 40) camera.rotation = 40;
        else if (camera.rotation < -40) camera.rotation = -40;

        // Camera zoom controls
        camera.zoom += ((float)GetMouseWheelMove()*0.05f);

        if (camera.zoom > 3.0f) camera.zoom = 3.0f;
        else if (camera.zoom < 0.1f) camera.zoom = 0.1f;

        // Camera reset (zoom and rotation)
        if (IsKeyPressed(KEY_R))
        {
            camera.zoom = 1.0f;
            camera.rotation = 0.0f;
        }
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        BeginMode2D(camera);

        DrawRectangle(-6000, 320, 13000, 8000, DARKGRAY);

        for (int i = 0; i < MAX_BUILDINGS; i++) DrawRectangleRec(buildings[i], buildColors[i]);

        DrawRectangleRec(player, RED);

        DrawLine(camera.target.x, -screenHeight*10, camera.target.x, screenHeight*10, GREEN);
        DrawLine(-screenWidth*10, camera.target.y, screenWidth*10, camera.target.y, GREEN);

        EndMode2D();

        DrawText("SCREEN AREA", 640, 10, 20, RED);

        DrawRectangle(0, 0, screenWidth, 5, RED);
        DrawRectangle(0, 5, 5, screenHeight - 10, RED);
        DrawRectangle(screenWidth - 5, 5, 5, screenHeight - 10, RED);
        DrawRectangle(0, screenHeight - 5, screenWidth, 5, RED);

        DrawRectangle( 10, 10, 250, 113, Fade(SKYBLUE, 0.5f));
        DrawRectangleLines( 10, 10, 250, 113, BLUE);

        DrawText("Free 2d camera controls:", 20, 20, 10, BLACK);
        DrawText("- Right/Left to move Offset", 40, 40, 10, DARKGRAY);
        DrawText("- Mouse Wheel to Zoom in-out", 40, 60, 10, DARKGRAY);
        DrawText("- A / S to Rotate", 40, 80, 10, DARKGRAY);
        DrawText("- R to reset Zoom and Rotation", 40, 100, 10, DARKGRAY);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
/**
 *  Función dedicada a dibujar cada frame. Acá adentro se debe poner la logica necesaria para representar un nuevo frame
 *  del juego.
 */
