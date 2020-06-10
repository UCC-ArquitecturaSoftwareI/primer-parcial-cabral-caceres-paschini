//
// Created by Catalina on 27/05/2020.
//

#ifndef RAYLIBTEMPLATE_MENU_H
#define RAYLIBTEMPLATE_MENU_H

#include <raylib.h>


class Menu {
private:
    Texture2D Background;
    Rectangle Rec_Menu{};
    float scrollingBack = 0.0f;
public:
    Menu();

    void Draw();
};


#endif //RAYLIBTEMPLATE_MENU_H
