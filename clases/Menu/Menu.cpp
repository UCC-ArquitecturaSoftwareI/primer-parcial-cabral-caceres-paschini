//
// Created by Catalina on 27/05/2020.
//

#include "Menu.h"


Menu::Menu() {

    InitWindow(1104, 688, "hola");
    Background = LoadTexture("../resources/Menu/Back_menu.png");
    Button = LoadTexture("../resources/Menu/Play.png)");

}

void Menu::Draw() {

    while (!WindowShouldClose()) {
        BeginDrawing();
        DrawTexture(Background, 0, 0, WHITE);
        DrawTexture(Button, 50, 50, WHITE);
        EndDrawing();
    }
}