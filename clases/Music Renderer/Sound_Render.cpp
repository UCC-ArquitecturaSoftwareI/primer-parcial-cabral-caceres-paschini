//
// Created by Martin on 20/04/2020.
//

#include "Sound_Render.h"

Sound_Render::Sound_Render(std::string text) {
    music = LoadMusicStream(text.c_str());
}

Music &Sound_Render::getMusic() {
    return music;
}

void Sound_Render::UpdateMusic() {
    UpdateMusicStream(music);
}
