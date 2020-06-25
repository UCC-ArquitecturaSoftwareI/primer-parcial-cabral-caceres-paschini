/**
 * @title       Clase GUI (Game User Interface)
 * @file        GUI.h
 * @version     1.0
 * @date        08/06/2020.
 * @author      Martin Caceres
 * @author      Camila Cabral
 * @author      Catalina Paschini
 */
#ifndef RAYLIBTEMPLATE_GUI_H
#define RAYLIBTEMPLATE_GUI_H

#include <raylib.h>
#include <string>
#include <ctime>
#include "../Character/Character.h"
/**
 * @class GUI
 * @brief Funcion que dibuja los rectangulos en la interfaz usuario y contola el tiempo
 */
class GUI {
private:
    Rectangle Rec_1{}; /**Rectangle value. Contiene el tiempo */
    Rectangle Rec_2{}; /**Rectangle value. Contiene la cantidad de frutas restantes*/
    Rectangle Rec_3{}; /**Rectangle value. Contiene mensaje sobre el volumen de la musica*/
    std::string Fruis_left; /**String value. Contiene la cantidad de frutas restantes*/
    std::string Sec; /** String value. Contiene la cantidad de segundos*/
    std::string Min; /** String value. Contiene la cantidad de minutos*/
    int Seconds; /**Int value. Contador de segundos*/
    int Minutes; /**Int value. Contador de minutos*/
    int timer; /**Int value. Contador de tiempo*/
    Character *Player; /**Puntero al jugador*/
public:
    /**
    * Constructor de GUI
    */
    GUI();
    /**
    * Funcion que carga al jugador
    *@param puntero al jugador
    */
    void LoadPlayer( Character *Play);
    /**
   * Funcion que dibuja la interfaz
   *@param amount
   *@param Time_stp
   */
    void DrawGui(int Amount, bool Time_stp);
    /**
   * Funcion que maneja el tiempo
   */
    void Take_Time();

};


#endif //RAYLIBTEMPLATE_GUI_H
