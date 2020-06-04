//
// Created by Catalina on 27/05/2020.
//

#ifndef RAYLIBTEMPLATE_MENU_H
#define RAYLIBTEMPLATE_MENU_H

#include <raylib.h>



class Menu {
private:
    Texture2D Background;
    Texture2D Button;
public:
    Menu ();

    void Draw();
};


#endif //RAYLIBTEMPLATE_MENU_H
