/**
 * @title       Clase Plant
 * @file        Plant.h
 * @version     1.0
 * @date        7/6/20.
 * @author      Martin Caceres
 * @author      Camila Cabral
 * @author      Catalina Paschini
 */
#ifndef RAYLIBTEMPLATE_PLANT_H
#define RAYLIBTEMPLATE_PLANT_H

#include "../../Entity/Entity.h"

#include "../Enemies.h"
/**
 * @class Plant
 * @brief Funcion para las Plant enemigas
 */
class Plant : public Enemies {
private:

public:
    /**
     * Funcion para colocar la posicion de la planta
     * @param file
     * @param playpos
     */
    Plant(std::string file, Vector2 playpos) : Enemies(std::move(file), playpos) {
        Proportion = {44, 42};
        maxCol = {7, 7, 10, 10};
        State_x = 1;
    }
    /**
     * Funcion que establece la animacion 3 en el eje x
     */
    void move_x();
    /**
     * Funcion sin retorno
     */
    void move_y();

};


#endif //RAYLIBTEMPLATE_PLANT_H
