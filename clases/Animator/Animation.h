/**
 * @title       Clase Animation
 * @file        Animation.h
 * @version     1.0
 * @date        26/04/2020.
 * @author      Martin Caceres
 * @author      Camila Cabral
 * @author      Catalina Paschini
 */

#ifndef RAYLIBTEMPLATE_ANIMATION_H
#define RAYLIBTEMPLATE_ANIMATION_H

#include <string>
#include "raylib.h"
#include <vector>
#include <fstream>
#include <unistd.h>
#include <iostream>
#include "Image_Holder.h"
/**
 * @class Animation
 * @brief Funcion que recorre las imagenes
 */
class Animation {
private:
    int currentRow;  /**int value. Especificamente va recorriendo imagen */
    int currentColumn; /** int value. Recorre las columnas*/
    Image_Holder *image; /** puntero de imagen*/
    Rectangle frameRec{};  /** toma el primer rectangulo */
public:
    /**
     * Constructor de la imagen
     * @param img
     */
    Animation(Image_Holder *img);
    /**
     * Funcion que contiene un vector para la posicion
     * @param pos
     */
    void Animate(Vector2 pos);
    /**
     * Fragmenta la imagen en rectangulos
     * @param pos
     */
    void Animte_Still(Vector2 pos);
    /**
     * toma los datos de su recorrida
     * @param currentRow
     */
    void setCurrentRow(int currentRow);

};


#endif //RAYLIBTEMPLATE_ANIMATION_H
