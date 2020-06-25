/**
 * @title       Clase Power_E
 * @file        Power_E.h
 * @version     1.0
 * @date        23/06/2020.
 * @author      Martin Caceres
 * @author      Camila Cabral
 * @author      Catalina Paschini
 */

#ifndef RAYLIBTEMPLATE_POWER_E_H
#define RAYLIBTEMPLATE_POWER_E_H

#include "../Power_Ups.h"
/**
 * @class Power_E
 * type: Super Speed
 * @brief Funcion que el poder de tipo E
 */
class Power_E : public Power_Ups{
public:
    /**
     * Constructor de Power_E
     * @param Pla
     */
    Power_E(Character *Pla);
    /**
     * Funcion de activacion de poderes
     */
    void Activate_Power();

};




#endif //RAYLIBTEMPLATE_POWER_E_H
