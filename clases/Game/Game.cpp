//
// Created by martin on 10/5/20.
//

#include "Game.h"

Game::Game() {
    const int screenWidth = 640 * 1.5;
    const int screenHeight = 480 * 1.5;

    //Inicialización de la ventana
    InitWindow(screenWidth, screenHeight, "raylib - Plataformer");
    InitAudioDevice();

    map = new Map("resources/level/Map.json");
    player = new Player();
    player->setClass("resources/Player/spritesheet.png", map->ReturnCharPos());
    Rend = new Renderer(map, player);
    Srend = new Sound_Render("resources/Music/Song.mp3");
    Input = new Input_Handler(player);
    Col = new Collision(map->ReturnList(), player);
}

void Game::PlayMusic() {
    Srend->PlayMusic();
}

void Game::UpdateFrame() {
    if (!Col->IsColliding()) {
        Input->setKeyPress();
        player->Move_x();
        player->Move_y();
        Rend->UpdateDrawFrame(Input->GetCharStatus());
    }
    if (player->GetSpeed().x != 0) {
        if (player->GetSpeed().x > 0)
            player->Deacelerate_x(-.1);
        else
            player->Deacelerate_x(.1);
    }
    if (player->GetSpeed().y != 0) {
        if (player->GetSpeed().y < 0)
            player->Jump_y(-.1);
        else
            player->Jump_y(.2);
    }
}

void Game::UpdateMusic() {
    Srend->UpdateMusic();
}

void Game::EndGame() {
    UnloadMusicStream(Srend->getMusic());   // Descargo la musica de RAM
    CloseAudioDevice();         // Cierro el dispositivo de Audio
    CloseWindow();              // Cierro la ventana
}


