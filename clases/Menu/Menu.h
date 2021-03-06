/**
 * @title       Clase Menu
 * @file        Menu.h
 * @version     1.0
 * @date        27/05/2020.
 * @author      Martin Caceres
 * @author      Camila Cabral
 * @author      Catalina Paschini
 */
#ifndef RAYLIBTEMPLATE_MENU_H
#define RAYLIBTEMPLATE_MENU_H

#include <raylib.h>
#include "../Music Renderer/Sound_Render.h"
#include "../State/State.h"

/**
 * @class Menu
 * @brief Funcion que crea el menu
 */

class Menu : public State {
private:
    Texture2D Background; /**Texture2D value. Contiene la textura del Background*/
    Texture2D WASD; /**Texture2D. Teclas WASD*/
    Texture2D RED_Fire; /**Texture2D fuego rojo*/
    Texture2D BLUE_Fire;/**Texture2D fuego azul*/
    Texture2D PINK_Fire;/**Texture2D fuego pink*/
    Texture2D PURPLE_Fire;/**Texture2D fuego pruple*/
    Texture2D GREEN_Fire;/**Texture2D fuego green*/
    Rectangle Back_;/**Rectanglue value. Rectangulo de texto de presentacion*/
    Rectangle Button;/**Rectanglue value. Reclangulo del boton play*/
    Rectangle Mouse;/**Rectanglue value. Rectangulo del mouse*/
    float scrollingBack = 0.0f; /** Float value. Velocidad de movimiento del background*/
    Sound_Render *Srend; /**Sound_Render value. Contiene el sound del menu*/
    int Goto;/**int value. Determina el proximo state al que va*/
public:
    /**
     * Constructor del menu
     */
    Menu();
    /**
     *  Funcion que actualiza el menu
     */
    void Update_Menu();
    /**
     * Funcion que dibuja el menu
     */
    void Draw();
    /**
     * Funcion que detecta inputs del teclado y del mouse
     */
    int Detect_Input();
    /**
     * Funcion override incia el menu
     */
    void On() override;
    /**
     * Funcion override finaliza el menu
     * @return goto
     */
    int Off() override;
    /**
     * Destructor del menu
     */
    ~Menu();

};


#endif //RAYLIBTEMPLATE_MENU_H