/**
 * @title       Clase Ending
 * @file        Ending.h
 * @version     1.0
 * @date        16/06/2020.
 * @author      Martin Caceres
 * @author      Camila Cabral
 * @author      Catalina Paschini
 */

#ifndef RAYLIBTEMPLATE_ENDING_H
#define RAYLIBTEMPLATE_ENDING_H

#include <raylib.h>
#include <string>
#include "../Music Renderer/Sound_Render.h"
#include "../State/State.h"
#include "../Animator/Animation_Creator.h"
/**
 * @class Ending
 * @brief Pantalla de seleccion de opciones en el juego
 */
class Ending : public State {
private:
    /**
     * Textura para el fondo del juego
     */
    Texture2D Background;
    /**
     * Rectangulo para la pantalla donde se mostrara las opciones en el juego
     */
    Rectangle Back_;
    /**
     * Botton de la opcion 1
     */
    Rectangle Button1;
    /**
     * Botton de la opcion 2
     */
    Rectangle Button2;
    /**
     * Rectangulo del mouse
     */
    Rectangle Mouse;
    /**
     *
     */
    float scrollingBack = 0.0f;
    /**
     * Muestra los resultados con los puntos, vida, entre otros
     */
    bool Result;
    /**
     * pasa como string los segundos
     */
    std::string Sec;
    /**
     * pasa como string los minutos
     */
    std::string Min;
    /**
     * Cancion en puntero porque si ganas hay una cancion y si perder hay otra cancion
     */
    Sound_Render *Srend;
    /**
     * int value, go to
     */
    int GoTo;

public:
    /**
     * Contuctor Ending
     * @brief Se difine donde va estar cada cosa en la pantalla que se le muestra al usuario cuando finaliza el juego
     */
    Ending();
  /**
   * Funcion de dibujo de la pantalla
   */
    void Draw();
   /**
    * Cancion del final cuando acaba el juego
    */
    void Update_End();
     /**
      * detecta el boton que aprieta si al menu o finaliza
      */
    void Detect_Input();
   /**
    * Estado encendido
    */
    void On() override;
    /**
     * Estado apagado
     * @return go to
     */
    int Off() override;
    /**
     * Lee el estado del player
     * @param w
     * @param vec
     */
    void LoadState(bool w, Vector2 vec);
};

#endif //RAYLIBTEMPLATE_ENDING_H
