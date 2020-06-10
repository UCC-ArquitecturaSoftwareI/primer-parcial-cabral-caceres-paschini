//
// Created by Martin on 20/04/2020.
//

#include "Sound_Render.h"

Sound_Render::Sound_Render(std::string text) {
    music = LoadMusicStream(text.c_str());
}

void Sound_Render::UpdateMusic() {
    UpdateMusicStream(music);
}

void Sound_Render::PlayMusic() {
    SetMusicVolume(music, 0.5);
    PlayMusicStream(music);
}

const Music &Sound_Render::getMusic() const {
    return music;
}

void Sound_Render::PlaySoundfx(std::string text) {
    Temp = LoadSound(text.c_str());
    PlaySound(Temp);
}
