/**
 * @title       Clase Sound_Render
 * @file        Sound_render.h
 * @version     1.0
 * @date        20/04/2020.
 * @author      Martin Caceres
 * @author      Camila Cabral
 * @author      Catalina Paschini
 */
#ifndef RAYLIBTEMPLATE_SOUND_RENDER_H
#define RAYLIBTEMPLATE_SOUND_RENDER_H

#include <raylib.h>
#include <string>
/**
 * @class Sound_Render
 * @brief Funcion maneja los sonidos del juego
 */
class Sound_Render {

private:
    Music music; /**Music value. Contiene el sonido a repoducir*/
    Sound Temp; /**Sound value. COntiene los sonidos del character*/
    int timer = 0; /**Int value. */
    float volume =0.2; /**Float value. Valor del volumen*/
public:
    /**
    * Constructor explicit del sound_render
    * @param text
    */
    explicit Sound_Render(std::string text);
    /**
     * Funcion que actualiza la musica
     */
    void UpdateMusic();
    /**
     * Funcion que inicia la musica
     */
    void PlayMusic();
    /**
     * Funcion que maneja los sonidos del character
     * @param text
     */
    void PlaySoundfx(std::string text);
    /**
     * Funcion que modifica el volumen
     */
    void ChangeVolume(float d);
    /**
     * Const funcion que retorna la musica
     * @return music
     */
    const Music &getMusic() const;

};


#endif //RAYLIBTEMPLATE_SOUND_RENDER_H
