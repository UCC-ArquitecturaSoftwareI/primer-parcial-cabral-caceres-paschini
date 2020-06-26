/**
 * @title       Clase Input_Handler
 * @file        Input_Handler.h
 * @version     1.0
 * @date        09/05/2020.
 * @author      Martin Caceres
 * @author      Camila Cabral
 * @author      Catalina Paschini
 */
#ifndef RAYLIBTEMPLATE_INPUT_HANDLER_H
#define RAYLIBTEMPLATE_INPUT_HANDLER_H

#include "raylib.h"
#include "../Character/Character.h"
#include "../Music Renderer/Sound_Render.h"
/**
 * @class Input_Handler
 * @brief Funcion maneja los eventos del teclado
 */
class Input_Handler {
private:
    Vector2 KeyPress;/**Vector2 value. Contiene las teclas apretadas*/
    Character *Play;/**Puntero al jugador*/
    Sound_Render *MUS;/**Puntero a los sonidos del juego*/
    bool CanJump;/**Bool value. Verifica si se puede saltar*/

public:
    /**
     * Constructor Input_Handler
     * @param Ch
     * @param MU
     */
    Input_Handler(Character *Ch, Sound_Render *MU);
    /**
     * Funcion que interpreta los eventos del teclado
     */
    void setKeyPress();
    /**
     * Funcion obtiene el estado del personaje
     */
    int GetCharStatus();
    /**
     * Funcion que verifica si puede saltar
     * @param can
     */
    void GetCanJump(bool can);

};


#endif //RAYLIBTEMPLATE_INPUT_HANDLER_H
