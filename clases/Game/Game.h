/**
 * @title       Clase Game
 * @file       Game.h
 * @version     1.0
 * @date        10/5/20.
 * @author      Martin Caceres
 * @author      Camila Cabral
 * @author      Catalina Paschini
*/
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
#include "../State/State.h"
#include "../Decorator/Player_Decorator.h"

class Game : public State {
private:
    Game();

    Map *map;   /** */
    Character *player;  /** */
    Sound_Render *Srend; /** */
    Renderer *Rend; /** */
    Input_Handler *Input;  /** */
    Collision *Col;  /** */
    World *world;   /** */
    Fruit_Vector *Fruits;  /** */
    std::vector<Enemies *> Bad_Guys;  /** */
    Enemies_factory *fac; /** */
    Player_Decorator *Pla;  /** */
    bool Won;  /** */
    int Power_Up;   /** */
    int GoTo;   /** */
    bool Time_Stp;  /** */

public:
    static Game &Get_Game() {
        static Game The_game;
        return The_game;
    }

    void PlayMusic();

    void UpdateFrame();

    void UpdateMusic();

    void Update_Game();

    void On() override;

    int Off() override;

    void Del();

    Vector2 GetTime();

    bool GetWon();

    void Reset_Game();
};


#endif //RAYLIBTEMPLATE_GAME_H
