/**
 * @title       Clase Fruit_Vector
 * @file        Fruit_Vector.h
 * @version     1.0
 * @date        20/5/20.
 * @author      Martin Caceres
 * @author      Camila Cabral
 * @author      Catalina Paschini
*/
#ifndef RAYLIBTEMPLATE_FRUITS_H
#define RAYLIBTEMPLATE_FRUITS_H


#include <raylib.h>
#include <string>
#include <vector>
#include "../Entity/Entity.h"
#include <random>
/**
 * @class Fruits
 * @brief Funcion para ir contando las frutas que el player va capturando
 */

class Fruits : public Entity {
private:
    bool picked_up;  /** Si atrapo la fruta*/
    int points;    /** int value. Puntos*/
public:

   /**
    * Funcion que determina una fruta de forma aletoria
    * @param file
    * @param playpos
    * @param Max_Col
    */
    Fruits(std::string file, Vector2 playpos, std::vector<int> Max_Col) : Entity(std::move(file), playpos,
                                                                                 std::move(Max_Col), Vector2{32, 32}) {
        int val = GetRandomValue(0, 7);
        picked_up = false;
        points = 100 * val;
    }
   /**
    * Funcion para saber si consiguio la fruta
    * @return picked_up
    */
    bool Is_picked();
    /**
     * Recupera los puntos
     * @return points
     */
    int Get_points();
    /**
     * Destructor de las frutas
     */
    ~Fruits();

};


#endif //RAYLIBTEMPLATE_FRUITS_H
