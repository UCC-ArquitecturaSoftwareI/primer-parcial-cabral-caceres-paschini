
#ifndef RAYLIBTEMPLATE_MENU_H
#define RAYLIBTEMPLATE_MENU_H

#include <raylib.h>
#include "../Music Renderer/Sound_Render.h"
#include "../State/State.h"


class Menu : public State {
private:
    Texture2D Background;
    Texture2D WASD;
    Texture2D RED_Fire;
    Texture2D BLUE_Fire;
    Texture2D PINK_Fire;
    Texture2D PURPLE_Fire;
    Texture2D GREEN_Fire;
    Rectangle Back_;
    Rectangle Button;
    Rectangle Mouse;
    float scrollingBack = 0.0f;
    Sound_Render *Srend;
    int Goto;
public:
    Menu();

    void Update_Menu();

    void Draw();

    int Detect_Input();

    void On() override;

    int Off() override;

    ~Menu();

};


#endif //RAYLIBTEMPLATE_MENU_H