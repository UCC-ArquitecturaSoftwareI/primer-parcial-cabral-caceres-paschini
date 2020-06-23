//
// Created by martin on 16/6/20.
//

#ifndef RAYLIBTEMPLATE_ENDING_H
#define RAYLIBTEMPLATE_ENDING_H

#include <raylib.h>
#include <string>
#include "../Music Renderer/Sound_Render.h"
#include "../State/State.h"
#include "../Animator/Animation_Creator.h"

class Ending : public State {
private:
    Texture2D Background;
    Rectangle Back_;
    Rectangle Button1;
    Rectangle Button2;
    Rectangle Mouse;
    float scrollingBack = 0.0f;
    bool Result;
    std::string Sec;
    std::string Min;
    Sound_Render *Srend;
    int GoTo;

public:
    Ending();

    void Draw();

    void Update_End();

    void Detect_Input();

    void On() override;

    int Off() override;

    void LoadState(bool w, Vector2 vec);
};

#endif //RAYLIBTEMPLATE_ENDING_H
