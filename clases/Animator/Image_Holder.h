/**
 * @title       Clase Imagen Holder
 * @file        Imagen_Holder.h
 * @version     1.0
 * @date        20/05/2020.
 * @author      Martin Caceres
 * @author      Camila Cabral
 * @author      Catalina Paschini
 */

#ifndef RAYLIBTEMPLATE_IMAGE_HOLDER_H
#define RAYLIBTEMPLATE_IMAGE_HOLDER_H

#include <string>
#include "raylib.h"
#include <vector>
/**
 * @class Imagen_Holder
 * @brief Funcion para saber la cantidad max de columnas en la imagen, y obtener su textura
 */
class Image_Holder {
private:
    /**
     * vector int, con max columnas
     * @brief Se usa para saber la cantidad de columnas que posee la imagen
     */
    std::vector<int> maxColumn;
    /**
     * Textura de la imagen
     */
    Texture2D Picture{};
    /**
     * Vector de la proporcion
     */
    Vector2 Proportion;
public:
    /**
     * Constructor de Imagen_Holder, que contiene fila, columnas y sus proporcion de la imagen
     * @param maxColumn
     * @param file
     * @param prop
     */
    Image_Holder(std::vector<int> maxColumn, std::string file, Vector2 prop);
    /**
     * Const value. Recure la textura de la picture
     * @return Picture
     */
    const Texture2D &getPicture() const;

    /**
     *  Vector entero que recupera cant maxima de columnas
     * @return maxColumn
     */
    const std::vector<int> &getMaxColumn() const;
     /**
      * Vector constante que recupera la proporcion de la imagen
      * @return Proporcion
      */
    const Vector2 &getProportion() const;
};


#endif //RAYLIBTEMPLATE_IMAGE_HOLDER_H
