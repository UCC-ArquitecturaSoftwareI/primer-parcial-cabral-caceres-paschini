/**
 * @title       Clase Power_A
 * @file        Power_A.h
 * @version     1.0
 * @date        23/06/2020.
 * @author      Martin Caceres
 * @author      Camila Cabral
 * @author      Catalina Paschini
 */

#ifndef RAYLIBTEMPLATE_POWER_A_H
#define RAYLIBTEMPLATE_POWER_A_H

#include "../Power_Ups.h"
/**
 * @class Power_A
 * type: fly
 * @brief Funcion que el poder de tipo A
 */
class Power_A : public Power_Ups{
public:
    /**
     * Constructor de Power_A
     * @param Pla
     */
    Power_A(Character *Pla);
    /**
    * Funcion de activacion de poderes
    */
    void Activate_Power();

};


#endif //RAYLIBTEMPLATE_POWER_A_H
