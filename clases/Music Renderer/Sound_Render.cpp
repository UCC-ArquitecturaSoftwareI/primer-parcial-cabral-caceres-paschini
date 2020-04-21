//
// Created by Martin on 20/04/2020.
//

#include "Sound_Render.h"

Sound_Render::Sound_Render(std::string text) {
    music = LoadMusicStream(text.c_str());
}

const Music &Sound_Render::getMusic() const {
    return music;
}

