//
// Created by Martin on 20/04/2020.
//

#ifndef RAYLIBTEMPLATE_SOUND_RENDER_H
#define RAYLIBTEMPLATE_SOUND_RENDER_H
#include <raylib.h>
#include <string>

class Sound_Render {
public:
    Sound_Render(const Music &music);

private:
Music music;
public:
    Sound_Render(std::string text);

    const Music &getMusic() const;


};


#endif //RAYLIBTEMPLATE_SOUND_RENDER_H
