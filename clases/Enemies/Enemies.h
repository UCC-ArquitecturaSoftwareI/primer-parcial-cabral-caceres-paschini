/**
 * @title       Clase Enemies
 * @file        Enemies.h
 * @version     1.0
 * @date        8/6/20.
 * @author      Martin Caceres
 * @author      Camila Cabral
 * @author      Catalina Paschini
 */
#ifndef RAYLIBTEMPLATE_ENEMIES_H
#define RAYLIBTEMPLATE_ENEMIES_H

#include "../Entity/Entity.h"
/**
 * @class Enemies
 * @brief Funcion para los enemigos
 */
class Enemies : public Entity {
protected:
    int State_x;  /** int value. Estado del enemigo en cordenada x */
    int State_y;  /** int value. Estado del enemigo en cordenada y */
    int Idle_Counter;  /** int value. Estado de los enemigos, es decir, la cantidad de tiempo que se tienen que quedar quietos */
public:
    /**
     *Inicializador del enemigo
     * @param file
     * @param playpos
     */
    Enemies(std::string file, Vector2 playpos) : Entity(file, playpos, {1}, {1, 1}) {
        filePathText = file;
        Entity_pos = playpos;
        State_x = 0;
        State_y = 0;
        Idle_Counter = 0;
    }
   /**
    * Funcion virtual pura abstracta
    * @brief sin instanciar
    */
    virtual void move_x() = 0;
    /**
    * Funcion virtual pura abstracta
    * @brief sin instanciar
    */
    virtual void move_y() = 0;
    /**
     * int value.Consigue el valor para que se pueda usar en el estado x
     * @return State_x
     */
    int Get_State_x();
    /**
     * int value. Consigue el valor para que se pueda usar en el estado y
     * @return State_y
     */
    int Get_State_y();
    /**
     * int value. Consigue el valor del estado del enemigo
     * @return Idle_Counter
     */
    int Get_Counter();
    /**
     * Establece el valor del Sate_x
     * @param s
     */
    void Set_Sate_x(int s);
     /**
      * Establece el valor del Sate_Y
      * @param s
      */
    void Set_Sate_y(int s);
};


#endif //RAYLIBTEMPLATE_ENEMIES_H
