#include "Sound_Render.h"

Sound_Render::Sound_Render(std::string text) {
    music = LoadMusicStream(text.c_str());
}

void Sound_Render::UpdateMusic() {
    SetMusicVolume(music, volume);
    UpdateMusicStream(music);
}

void Sound_Render::PlayMusic() {
    SetMusicVolume(music, volume);
    PlayMusicStream(music);
}

const Music &Sound_Render::getMusic() const {
    return music;
}

void Sound_Render::ChangeVolume(float d) {
    volume += d;
    if (volume > 10)
        volume = 1;
    if (volume < 0)
        volume = 0;
}

void Sound_Render::PlaySoundfx(std::string text) {
    Temp = LoadSound(text.c_str());
    SetSoundVolume(Temp,volume);
    PlaySound(Temp);
}




