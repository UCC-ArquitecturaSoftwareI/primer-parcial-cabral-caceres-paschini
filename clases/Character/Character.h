/**
 * @title       Clase Character
 * @file        Character.h
 * @version     1.0
 * @date        21/03/2020.
 * @author      Martin Caceres
 * @author      Camila Cabral
 * @author      Catalina Paschini
 */

#ifndef RAYLIBTEMPLATE_NAVE_H
#define RAYLIBTEMPLATE_NAVE_H

#include <raylib.h>
#include <string>
#include <utility>
#include <vector>
#include "../Entity/Entity.h"
/**
 * @class Character
 * @brief Movimientos de los personajes
 */

class Character : public Entity {
private:
    Vector2 player_Spd{};  /** vector del jugador_spd */
    float Spd_Multi;      /** float value, multi */
    float Max_Speed;      /** float value, la velocidad maxima*/
    int Fruits_Left;      /** inst value. Espeficifica las frutas de largo */
    int life;            /** int value. Especifica la vida*/
    int Invulnerable = 0;   /** int value. Especifica la invulnerabilidad*/
    Vector2 Time;          /** Vector con el tiempo */
public:
   /**
    * Constructor obtiene los datos de la imagen, con su cantidad de filas, columnas.
    * @brief Se asigna la velocidad maxima, vidas,tiempo de inicio
    * @param file
    * @param playpos
    * @param Max_Col
    */
    Character(std::string file, Vector2 playpos, std::vector<int> Max_Col) : Entity(std::move(file), playpos,
                                                                                    std::move(Max_Col),
                                                                                    Vector2{32, 32}) {
        player_Spd = {0, 0.1};
        Fruits_Left = 35;
        life = 3;
        Time = {0, 0};
        Spd_Multi = 1;
        Max_Speed = 3;
    }
   /**
    * Funcion para que el player acelere
    * @param d
    */
    void Acelerate_x(float d);
   /**
    * Funcion para que el player vaya frenando
    * @param d
    */
    void Deacelerate_x(float d);
   /**
    * Funcion para que el jugador salte
    * @param d
    */
    void Jump_y(float d);
    /**
     * Funcion para que se mueve en la cordenada x
     */
    void Move_x();
    /**
     * Funcion para que se mueva en la cordenada y
     */
    void Move_y();
    /**
     * Funcion para que le den un valor a la velocidad en el eje x
     * @param d
     */
    void Setspeed_x(float d);
    /**
     * Funcion para que le den un valor a la velocidad en el eje y
     * @param d
     */
    void Setspeed_y(float d);
    /**
     * Vector de la velocidad del player
     * @return player
     */
    Vector2 GetSpeed();
   /**
    * Cnatidad de vidas
    * @param d
    */
    void Change_life(int d);
    /**
     * Cantidad de frutas recolectadas
     */
    void Collect();
    /**
     * Numeros de vidas
     * @return life
     */
    int Get_life_Num();
    /**
     * Comprueba si las vidas no son = 0
     * @return
     */
    bool Is_alive();
    /**
     * Toma la imagen de la fruta, ya que l jugador la obtuvo
     * @return
     */
    int Get_Fruits_left();
   /**
    * Estable el tiempo en minutos
    * @param F
    */
    void SetMin(int F);
    /**
     * Establece el tiempo en segundos
     * @param F
     */
    void SetSec(int F);
    /**
     * Recoge informacion del tiempo
     * @return  time
     */
    const Vector2 &getTime() const;
    /**
     * Establece lo invulnerable
     * @param invulnerable
     */
    void SetInvulnerable(int invulnerable);
     /**
      * restador de vidas
      */
    void LessInv();
     /**
      * recoge su estado de vida
      * @return invulnerable
      */
    int GetInvulnerable();
    /**
     * Funcion para el spdMulti
     * @param spdMulti
     */
    void SetSpdMulti(float spdMulti);
     /**
      * Maxima velocidad
      * @param Max
      */
    void Set_MaxSpeed(float Max);
};


#endif //RAYLIBTEMPLATE_NAVE_H