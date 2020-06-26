/**
 * @title       Clase Renderer
 * @file        Renderer.h
 * @version     1.0
 * @date        20/04/2020.
 * @author      Martin Caceres
 * @author      Camila Cabral
 * @author      Catalina Paschini
 */

#ifndef RAYLIBTEMPLATE_RENDERER_H
#define RAYLIBTEMPLATE_RENDERER_H

#include "../Map/Map.h"
#include "../Character/Character.h"
#include "../Decorator/Player_Decorator.h"
#include "../Fruits/Fruit_Vector.h"
#include "../Animator/Animation_Creator.h"
#include "../Enemies/Enemies.h"
#include "../Entity/All_entity.h"
#include "../GUI/GUI.h"
/**
 * @class Renderer
 * @brief Dibuja
 */

class Renderer {
private:
    Map *Level; /**Puntero a level*/
    Character *Chara; /**Puntero a chara*/
    Fruit_Vector *Fruits; /**Puntero a frutas*/
    Player_Decorator *Dec; /**Punero a dec*/
    Animation_Creator Ani_Creator; /**Animation_creator value*/
    Texture2D Background; /**Texture2D value. Contiene el background del nivel*/
    Camera2D camZoom; /**Camara2D value. Define camZoom como una camara 2D*/
    Entity *Life; /**Puntero a life*/
    All_entity *Entities;  /**puntero a Entities*/
    int frameCounter = 0; /**int Value. Contador de frames*/
    std::vector<Enemies *> *Bad_Guys; /**Puntero a Bad_guy*/
    float scrollingBack = 0.0f;/**Float value. Velocidad del background*/
    Shader Shade; /**Shader value. Modifica posprocesado */
    class GUI Interface; /**Interfaz de usuario*/
    int swirlCenterLoc; /**Int value. */
    float Swirl_center[2] = {1104 / 2, 688 / 2};; /***/

public:
    /**
     * Constructor de Renderer
     * @param Mp
     * @param Ch
     * @param Vec
     * @param Ene
     * @param Pla
     */
    Renderer(Map *Mp, Character *Ch, Fruit_Vector *Vec, std::vector<Enemies *> *Ene, Player_Decorator *Pla);
    /**
    * Funcion que dibuja al mapa
    */
    void draw_Map();
    /**
   * funcion que actualiza la pantalla
   * @param State
   * @param Time_Stp
   */
    void UpdateDrawFrame(int State, bool Time_Stp);
    /**
     * funcion que actualiza los efectos
     * @param Pl
     * */
    void Update_Fx(Player_Decorator *Pl);


};


#endif //RAYLIBTEMPLATE_RENDERER_H
