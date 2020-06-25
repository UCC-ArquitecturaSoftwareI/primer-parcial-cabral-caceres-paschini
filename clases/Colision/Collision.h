/**
 * @title       Clase Collision
 * @file        Collision.h
 * @version     1.0
 * @date        10/05/2020.
 * @author      Martin Caceres
 * @author      Camila Cabral
 * @author      Catalina Paschini
 */

#ifndef RAYLIBTEMPLATE_COLLISION_H
#define RAYLIBTEMPLATE_COLLISION_H

#include <raylib.h>
#include "../Character/Character.h"
#include "../Enemies/Enemies.h"
#include "../Fruits/Fruits.h"
#include <vector>
/**
 * @class Collision
 * @brief Funcion para saber donde estan colisiones
 */

class Collision {
private:
    std::vector<Rectangle> *Floor_Wall;  /** puntero del suelo */
    std::vector<Rectangle> *Plataform;   /** puntero de las plataformas flotantes*/
    std::vector<Rectangle> *Traps;      /**  puntero de trampas*/
    std::vector<Fruits *> *Fruits_Vec;    /** puntero de frutas */
    Rectangle Ent_Rec;           /** rectangulos para los player */
    Rectangle Enemie_Rec;       /** rectangulos para el enemigo*/
    Rectangle Fruit_area;        /**  rectangulos para la fruta*/

public:
    /**
     * Constructor de Collision
     */
    Collision();
     /**
      * Funcion para saber cuando va a colisionar con la fruta el juegador
      * @param vec
      */
    void Load_Vector(std::vector<Fruits*> *vec);
    /**
     * Funcion para saber colision de piso, trampas y plataformas flotante
     * @param vec
     * @param Dat
     */

    void Load_Vector(std::vector<Rectangle> *vec, int Dat);
  /**
   * Funcion para saber si toco el enemigo alguna pared o piso en eje x
   * @param Ent
   * @return
   */
    bool IsColliding_X(Enemies *Ent);
   /**
    * Funcion para saber si toco a un enemigo el player en el eje x
    * @param Ent
    * @return
    */
    bool IsColliding_X(Character *Ent);
    /**
     * Funcion para saber si toco a un enemigo el player en el eje y
     * @param Ent
     * @return
     */
    bool IsColliding_y(Enemies *Ent);
    /**
     * Funcion para saber si toco a un enemigo el player en el eje y
     */
    bool IsColliding_y(Character *Ent);
    /**
     * Colision de la plataformas flotantes
     * @param Ent
     * @return
     */
    bool IsCollidingPlataform(Character *Ent);
    /**
     * Colision cuando salte
     * @param Ent
     * @return true or false
     */
    bool IsFlying(Character *Ent);
    /**
     * Coleccion del area del rectangulo
     * @param Ent
     * @return
     */
    bool IsCollecting(Character *Ent);
    /**
     * Colision con trampas
     * @param Ent
     * @return
     */
    bool Dmg(Character *Ent);
   /**
    * Colision con punteros de enemigo y player
    * Colisionar con pared, plataformas, y piso
    * @param Ent
    * @param Ene
    * @return
    */
    bool Dmg(Character *Ent,Enemies *Ene);
};


#endif //RAYLIBTEMPLATE_COLLISION_H
