//
// Created by martin on 10/5/20.
//

#include "Game.h"

Game::Game() {
    const int screenWidth = 1104 ;
    const int screenHeight = 688 ;

    //Inicialización de la ventana
    InitWindow(screenWidth, screenHeight, "raylib - Plataformer");
    InitAudioDevice();

    map = new Map("resources/level/Map1.json");
    player = new Character("resources/Player/spritesheet.png", map->ReturnCharPos(),  {6, 5, 5, 1, 1, 10, 10, 11, 11, 4, 4});
    Vec = new Fruit_Vector(map->Get_Fruits());

    Rend = new Renderer(map,player,Vec);
    Srend = new Sound_Render("resources/Music/Song.mp3");
    Input = new Input_Handler(player);



    Col = new Collision(player);
    Col->LoadList(map->ReturnList(0));
    Col->LoadList(map->ReturnList(1));
    Col->LoadList(map->ReturnTraps());
    Col->LoadVector(Vec->Get_Vec_pointer());

    world = new World(player);
}

void Game::PlayMusic() {
    Srend->PlayMusic();
}

void Game::UpdateFrame() {
    //Check key inputs
    Input->setKeyPress();

    //Move player x cordinates
    player->Move_x();
    world->Friction();
    Col->IsColliding_X();

    //Move player y cordinates
    player->Move_y();

    if (Col->IsFlying())
        world->Gravity();

    Col->IsColliding_y();
    Col->IsCollidingPlataform();
    Input->GetCanJump(player->GetSpeed().y == 0);
    //Draw the result

    //Fruits
    Col->IsCollecting();

    //Damage
    Col->Is_getting_damage();

    Rend->UpdateDrawFrame(Input->GetCharStatus());
    if (player->Is_alive())
        CloseWindow();

}

void Game::UpdateMusic() {
   // Srend->UpdateMusic();
}

void Game::EndGame() {
    UnloadMusicStream(Srend->getMusic());   // Descargo la musica de RAM
    CloseAudioDevice();         // Cierro el dispositivo de Audio
    CloseWindow();              // Cierro la ventana
}

void Game::Update_Game() {
    while (!WindowShouldClose()) {
        UpdateFrame();
        UpdateMusic();
    }
}


