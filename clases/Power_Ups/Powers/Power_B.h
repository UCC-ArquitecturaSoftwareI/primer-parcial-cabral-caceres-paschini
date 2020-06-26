/**
 * @title       Clase Power_B
 * @file        Power_B.h
 * @version     1.0
 * @date        23/06/2020.
 * @author      Martin Caceres
 * @author      Camila Cabral
 * @author      Catalina Paschini
 */
#ifndef RAYLIBTEMPLATE_POWER_B_H
#define RAYLIBTEMPLATE_POWER_B_H

#include "../Power_Ups.h"
/**
 * @class Power_B
 * type: Slow
 * @brief Funcion que el poder de tipo B
 */
class Power_B : public Power_Ups{
public:
    /**
     * Constructor de Power_B
     * @param Pla
     */
    Power_B(Character *Pla);
    /**
     * Funcion de activacion de poderes
     */
    void Activate_Power();


};



#endif //RAYLIBTEMPLATE_POWER_B_H
