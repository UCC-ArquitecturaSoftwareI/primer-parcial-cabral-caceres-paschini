/**
 * @title       Clase Power_D
 * @file        Power_D.h
 * @version     1.0
 * @date        23/06/2020.
 * @author      Martin Caceres
 * @author      Camila Cabral
 * @author      Catalina Paschini
 */

#ifndef RAYLIBTEMPLATE_POWER_D_H
#define RAYLIBTEMPLATE_POWER_D_H

#include "../Power_Ups.h"
/**
 * @class Power_D
 * type: Time Stop
 * @brief Funcion que el poder de tipo D
 */
class Power_D : public Power_Ups{
public:
    /**
     * Constructor de Power_D
     * @param Pla
     */
    Power_D(Character *Pla);
    /**
     * Funcion de activacion de poderes
     */
    void Activate_Power();


};

#endif //RAYLIBTEMPLATE_POWER_D_H
