/**
 * @title       Clase Player_Decorator
 * @file        Player Decorator.h
 * @version     1.0
 * @date        23/06/2020.
 * @author      Martin Caceres
 * @author      Camila Cabral
 * @author      Catalina Paschini
 */

#ifndef RAYLIBTEMPLATE_PLAYER_DECORATOR_H
#define RAYLIBTEMPLATE_PLAYER_DECORATOR_H

#include "../Character/Character.h"
#include "../Power_Ups/Power_Ups.h"
#include "../Power_Ups/Powers/Power_A.h"
#include "../Power_Ups/Powers/Power_B.h"
#include "../Power_Ups/Powers/Power_C.h"
#include "../Power_Ups/Powers/Power_D.h"
#include "../Power_Ups/Powers/Power_E.h"
/**
 * @class Player_Decorator
 * @brief Funcion para el uso de los poderes del player
 */

class Player_Decorator {
private:
    Power_Ups *Power;  /** puntero de encendido*/
    Character *Player; /**  puntero del jugador*/
    Animation *Ani;   /** puntero de la aniamcion*/
    int Cu_Power;    /**  int value. Poderes*/
public:
    /**
     * Contructor para los distintos casos de poderes, se generan de manera aleatoria
     * @param chara
     */
    Player_Decorator(Character *chara);
    /**
     * Dibuja al jugador con su poder
     */
    void DrawFx();
    /**
     * @return poder
     */
    bool Get_Timer();
    /**
     * Funcion del poder que reduce el tiempo
     */
    void Reduce_Timer();
     /**
      * Desconstructor de poder que le otorga al jugador
      */
    ~Player_Decorator();
     /**
      * Funcion para el Poder activo
      */
    void Activate_Power();
     /**
      * int value. Especifica el valor del poder
      * @return Poder
      */
    int Get_Type();

};


#endif //RAYLIBTEMPLATE_PLAYER_DECORATOR_H
