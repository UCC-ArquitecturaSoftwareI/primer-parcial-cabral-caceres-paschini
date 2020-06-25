/**
 * @title       Clase Power_Ups
 * @file        Power_Ups.h
 * @version     1.0
 * @date        23/06/2020.
 * @author      Martin Caceres
 * @author      Camila Cabral
 * @author      Catalina Paschini
 */


#ifndef RAYLIBTEMPLATE_POWER_UPS_H
#define RAYLIBTEMPLATE_POWER_UPS_H

#include "../Animator/Image_Holder.h"
#include <vector>
#include "../Animator/Animation.h"
#include "../Character/Character.h"
/**
 * @class Power_Ups
 * @brief Funcion que realiza poderes
 */
class Power_Ups {
protected:
    Image_Holder *Img{}; /**Puntero a Img*/
    Character *Player; /**Puntero a Player*/
    int Timer; /**Int value. */
    int Type; /**Int value. Tipo de power up*/
public:
    /**
     * Constructor de Power_ups
     */
    Power_Ups();
    /**
     * Funcion que obtiene imagen
     * @return Img
     */
    Image_Holder *Get_Img();
    /**
     * Funcion virtualmente pura de activacion de poderes
     */
    virtual void Activate_Power() = 0;
    /**
     * Destructor de Power_up
     */
    ~Power_Ups();
    /**
     * Funcion que obtiene timer
     * @return timer
     */
    int Return_Timer();
    /**
     * Funcion que decrementa timer
     */
    void Reduce_timer();
    /**
     * Funcion que obtiene el tipo de poder
     * @return type
     */
    int Return_Type();
};


#endif //RAYLIBTEMPLATE_POWER_UPS_H
