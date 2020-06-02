//
// Created by Catalina on 27/05/2020.
//

#include "Menu.h"

Menu::Menu( std::string BackgroundFile, std::string ButtonFile) {

    InitWindow( 1104, 688, "raylib - Plataformer");
    BackgroundMenu= LoadTexture(BackgroundFile.c_str());
    ButtonMenu = LoadTexture(ButtonFile.c_str());
}

void Menu::DrawMenu() {

        DrawTexture(BackgroundMenu, 0, 0, BLACK);
        DrawTexture(ButtonMenu,640, 480, WHITE);

}
