//
// Created by Catalina on 27/05/2020.
//

#ifndef RAYLIBTEMPLATE_MENU_H
#define RAYLIBTEMPLATE_MENU_H

#include <raylib.h>
#include "../Game/Game.h"
#include <string>
class Menu{
private:
    Texture2D BackgroundMenu{};
    Texture2D ButtonMenu{};
    Rectangle Rec_Background{};
    Rectangle Rec_Button{};
public:
    Menu( std::string BackgroundFile,  std::string ButtonFile);

    void DrawMenu();

};


#endif //RAYLIBTEMPLATE_MENU_H
