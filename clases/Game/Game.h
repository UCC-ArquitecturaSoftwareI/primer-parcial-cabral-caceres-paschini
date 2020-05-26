//
// Created by martin on 10/5/20.
//

#ifndef RAYLIBTEMPLATE_GAME_H
#define RAYLIBTEMPLATE_GAME_H

#include "../Character/Character.h"
#include "../Map/Map.h"
#include "../Renderer/Renderer.h"
#include "../Music Renderer/Sound_Render.h"
#include "../Input/Input_Handler.h"
#include "../Colision/Collision.h"
#include "../World/World.h"
#include "../Fruits/Fruit_Vector.h"
#include "../Entity/All_entity.h"


class Game {
private:
    Map *map;
    Character *player;
    Sound_Render *Srend;
    Renderer *Rend;
    Input_Handler *Input;
    Collision *Col;
    World *world;
    Fruit_Vector *Vec;
    All_entity *Entities;

public:
    Game();

    void PlayMusic();

    void UpdateFrame();

    void UpdateMusic();

    void Update_Game();

    void EndGame();
};


#endif //RAYLIBTEMPLATE_GAME_H
