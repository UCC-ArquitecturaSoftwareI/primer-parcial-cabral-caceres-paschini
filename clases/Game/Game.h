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

    Map *map;   /** Puntero del map */
    Character *player;  /** Puntero del player*/
    Sound_Render *Srend; /**  Puntero para sonido*/
    Renderer *Rend; /** Puntero Rend */
    Input_Handler *Input;  /** vector input*/
    Collision *Col;  /** vector columna */
    World *world;   /** vector mundo*/
    Fruit_Vector *Fruits;  /** vector fruta*/
    std::vector<Enemies *> Bad_Guys;  /** Vector con puntero enemies */
    Enemies_factory *fac; /** puntero fac*/
    Player_Decorator *Pla;  /** puntero player*/
    bool Won;  /** Posibilidad de ganar */
    int Power_Up;   /** int value.Especifica el poder*/
    int GoTo;   /**int value. Espefica a donde va */
    bool Time_Stp;  /** Tiempo pare */

public:
    static Game &Get_Game() {
        static Game The_game;
        return The_game;
    }
/**
 *Funcion que inicializa la Musica
 */
    void PlayMusic();
/**
 *Funcion que da sonidos segundo el movimiento del player
 */
    void UpdateFrame();
/**
 *Funcion Musica
 */
    void UpdateMusic();
/**
 * Funcion que si pierde o no mueve para el sonido del movimiento
 */
    void Update_Game();
/**
 * Funcion que usa State para saber si continua con los sonidos
 */
    void On() override;
/**
 *Funcion para cuando el juego termina
 * @return
 */
    int Off() override;
/**
 *Funcion que borra todo del juego
 */
    void Del();
/**
 * Vector para el tiempo, cuando el juegador esta en el mapa
 * @return
 */
    Vector2 GetTime();
/**
 * Posibles valores de ganador o loser
 * @return
 */
    bool GetWon();
   /**
    * Resetea el juego
    */
    void Reset_Game();
};


#endif //RAYLIBTEMPLATE_GAME_H
