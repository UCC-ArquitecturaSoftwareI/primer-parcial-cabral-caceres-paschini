//
// Created by martin on 10/5/20.
//

#ifndef RAYLIBTEMPLATE_GAME_H
#define RAYLIBTEMPLATE_GAME_H

#include "../Personaje/Player.h"
#include "../Map/Map.h"
#include "../Renderer/Renderer.h"
#include "../Music Renderer/Sound_Render.h"
#include "../Input/Input_Handler.h"
#include "../Colision/Collision.h"


class Game {
private:
    Map *map;
    Player *player;
    Sound_Render *Srend;
    Renderer *Rend;
    Input_Handler *Input;
    Collision *Col;

public:
    Game();

    void PlayMusic();

    void UpdateFrame();

    void UpdateMusic();

    void EndGame();
};


#endif //RAYLIBTEMPLATE_GAME_H
