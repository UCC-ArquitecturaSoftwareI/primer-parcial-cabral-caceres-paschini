/**
 * @title       Clase Power_C
 * @file        Power_C.h
 * @version     1.0
 * @date        23/06/2020.
 * @author      Martin Caceres
 * @author      Camila Cabral
 * @author      Catalina Paschini
 */

#ifndef RAYLIBTEMPLATE_POWER_C_H
#define RAYLIBTEMPLATE_POWER_C_H

#include "../Power_Ups.h"
/**
 * @class Power_C
 * type: Add life
 * @brief Funcion que el poder de tipo C
 */
class Power_C : public Power_Ups{
public:
    /**
     * Constructor de Power_C
     * @param Pla
     */
    Power_C(Character *Pla);
    /**
     * Funcion de activacion de poderes
     */
    void Activate_Power();


};



#endif //RAYLIBTEMPLATE_POWER_C_H
