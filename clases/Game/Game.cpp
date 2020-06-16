//
// Created by martin on 10/5/20.
//

#include "Game.h"

Game::Game() {
    const int screenWidth = 1104;
    const int screenHeight = 688;

    Game_State = 0;

    //Inicialización de la ventana
    //InitWindow(screenWidth, screenHeight, "raylib - Plataformer");

    map = new Map("resources/level/Map1.json");
    player = new Character("resources/Player/spritesheet.png", map->ReturnCharPos(),
                           {6, 5, 5, 1, 1, 10, 10, 11, 11, 4, 4});

    Fruits = new Fruit_Vector(*map->Get_Fruits());

    Enemies_factory fac{};
    fac.Set_Map(map->Get_enemies());
    Bad_Guys = fac.Make_Enemies();

    Rend = new Renderer(map, player, Fruits, &Bad_Guys);
    Srend = new Sound_Render("resources/Music/Bad_song.mp3");
    Input = new Input_Handler(player, Srend);


    Col = new Collision();
    Col->Load_Vector(map->Return_Floor(), 0);
    Col->Load_Vector(map->Return_Plataform(), 1);
    Col->Load_Vector(map->ReturnTraps(), 2);
    Col->Load_Vector(Fruits->Get_Vec_pointer());

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
    Col->IsColliding_X(player);

    //Move player y cordinates
    player->Move_y();

    if (Col->IsFlying(player))
        world->Gravity();


    Col->IsColliding_y(player);
    Col->IsCollidingPlataform(player);
    Input->GetCanJump(player->GetSpeed().y == 0);

    int State = Input->GetCharStatus();
    //Fruits
    if (Col->IsCollecting(player)) {
        Fruits->Delete_fruit();
        Srend->PlaySoundfx("resources/Music/Pick_FX.mp3");
    }

    //Damage Spikes
    if (Col->Dmg(player) && player->GetInvulnerable() == 0) {
        State = 0;
        player->Change_life(-1);
        player->SetInvulnerable(80);
        Srend->PlaySoundfx("resources/Music/DMG.mp3");
    }

    for (auto i:Bad_Guys) {
        //Dmg Enemies
        if (Col->Dmg(player, i) && player->GetInvulnerable() == 0) {
            State = 0;
            player->Change_life(-1);
            player->SetInvulnerable(80);
            Srend->PlaySoundfx("resources/Music/DMG.mp3");
        }
        i->move_x();
        Col->IsColliding_X(i);
        i->move_y();
        Col->IsColliding_y(i);
    }

    if (player->GetInvulnerable() != 0) {
        player->LessInv();
    }
    //Draw the result
    Rend->UpdateDrawFrame(State);
    if (player->Is_alive())
        Game_State = 2;
    else
        Game_State = 1;
    if (player->Get_Fruits_left() == 0) {
        Game_State = 3;
    }
}

void Game::UpdateMusic() {
    Srend->UpdateMusic();
}

void Game::EndGame() {
    UnloadMusicStream(Srend->getMusic());   // Descargo la musica de RAM
}

void Game::Update_Game() {
    while (!WindowShouldClose()) {
        UpdateFrame();
        UpdateMusic();
    }
}

int Game::ReturnGameState() {
    return Game_State;
}



