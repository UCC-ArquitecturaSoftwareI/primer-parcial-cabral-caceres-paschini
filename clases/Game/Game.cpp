//
// Created by martin on 10/5/20.
//

#include "Game.h"

Game::Game(){
    map = new Map("resources/level/Map.json");
    player = new Player("resources/Player/spritesheet.png", map->ReturnCharPos());
    Rend = new Renderer(map, player);
    Srend = new Sound_Render("resources/Music/Song.mp3");
    Input = new Input_Handler(player);
}

void Game::PlayMusic() {
    Srend->PlayMusic();
}

void Game::UpdateFrame() {
    Input->setKeyPress();
    Rend->UpdateDrawFrame(Input->GetCharStatus());
}

void Game::UpdateMusic() {
    Srend->UpdateMusic();
}


