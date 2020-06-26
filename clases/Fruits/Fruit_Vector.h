/**
 * @title       Clase Fruit_Vector
 * @file        Fruit_Vector.h
 * @version     1.0
 * @date        21/5/20.
 * @author      Martin Caceres
 * @author      Camila Cabral
 * @author      Catalina Paschini
*/
#ifndef RAYLIBTEMPLATE_FRUIT_VECTOR_H
#define RAYLIBTEMPLATE_FRUIT_VECTOR_H

#include "Fruits.h"
#include <vector>
/**
 * @class Fruit_Vector
 * @brief
 */

class Fruit_Vector {
private:
    /**
     * Vector con puntero Fruits
     */
    std::vector<Fruits *> Fruits_Vec;
    int Amount = 0;
public:
    /**
     *Contructor que toma la pos_fruits
     * @param Pos_fruits
     */
    Fruit_Vector(std::vector<Vector2> Pos_fruits);
    /**
     * puntero de frutas , y recupera los puntos
     * @return
     */
    std::vector<Fruits *> *Get_Vec_pointer();
    /**
     *Establece el valor de frutas
     */
    void Set_fruit_type();
   /**
    * Funcion que llama al animador
    */
    void Call_Animator();
    /**
     * Funcion que llama a la animacion still
     */
    void Call_Animator_Still();
    /**
     * Funcion que elimina la fruta
     */
    void Delete_fruit();
   /**
    * Recupera las atrapadas
    * @return
    */
    int Get_Amount();

};


#endif //RAYLIBTEMPLATE_FRUIT_VECTOR_H
