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
#include "../Enemies/Enemies_factory.h"

class Game {
private:
    Game();

    Map *map;
    Character *player;
    Sound_Render *Srend;
    Renderer *Rend;
    Input_Handler *Input;
    Collision *Col;
    World *world;
    Fruit_Vector *Fruits;
    std::vector<Enemies*> Bad_Guys;
    int Game_State;

public:
    static Game &Get_Game(){
        static Game The_game;
        return The_game;
    }

    void PlayMusic();

    void UpdateFrame();

    void UpdateMusic();

    void Update_Game();

    void EndGame();

    int ReturnGameState();
};


#endif //RAYLIBTEMPLATE_GAME_H
