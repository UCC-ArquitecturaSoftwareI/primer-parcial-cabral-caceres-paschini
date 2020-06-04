//
// Created by Catalina on 27/05/2020.
//

#include "Menu.h"



Menu::Menu() {

    Background=LoadTexture(R"(../resources/Menu/Gray.png)");
    Button=LoadTexture(R"(../resources/Menu/Play.png)");

}

void Menu::Draw() {



    DrawTexture(Background,0,0, WHITE);
    DrawTexture(Button,552,344,WHITE);

}