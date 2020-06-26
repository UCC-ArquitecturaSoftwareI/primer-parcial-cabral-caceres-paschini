//
// Created by Martin on 20/04/2020.
//

#ifndef RAYLIBTEMPLATE_SOUND_RENDER_H
#define RAYLIBTEMPLATE_SOUND_RENDER_H

#include <raylib.h>
#include <string>

class Sound_Render {

private:
    Music music;
    Sound Temp;
    int timer = 0;
    float volume =0.2;
public:
    explicit Sound_Render(std::string text);

    void UpdateMusic();

    void PlayMusic();

    void PlaySoundfx(std::string text);

    void ChangeVolume(float d);

    const Music &getMusic() const;

};


#endif //RAYLIBTEMPLATE_SOUND_RENDER_H
