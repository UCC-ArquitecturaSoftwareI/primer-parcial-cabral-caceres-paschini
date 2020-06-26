/**
 * @title       Clase All_Entity
 * @file        All_Entity.h
 * @version     1.0
 * @date        21/5/20.
 * @author      Martin Caceres
 * @author      Camila Cabral
 * @author      Catalina Paschini
*/
#ifndef RAYLIBTEMPLATE_ALL_ENTITY_H
#define RAYLIBTEMPLATE_ALL_ENTITY_H


#include "Entity.h"
#include "../Fruits/Fruits.h"
#include "../Enemies/Enemies.h"
/**
 * @class All_Entity
 * @brief Funcion para todas las entidades
 */
class All_entity {
private:
    /**
     * Vector con puntero Entity
     */
    std::vector<Entity*> All_Ent;
public:
    /**
     * Constructor
     */
    All_entity();
    /**
     * Funcion  con puntero Entidad
     * @param Ent
     */
    void Add_entity(Entity * Ent);
    /**
     * Funcion con un vector puntero enemigos
     * @param Vec
     */
    void Add_entity(std::vector<Enemies*> *Vec);
     /**
      * Funcion con un vector puntero fruta
      * @param Vec
      */
    void Add_entity(std::vector<Fruits *> *Vec);
    /**
     * Funcion para todas Entidades
     * @return
     */
    std::vector<Entity *> *Get_Entities();
     /**
      * Funcion para llamar a la Animacion
      */
    void Call_Ani();
};


#endif //RAYLIBTEMPLATE_ALL_ENTITY_H
