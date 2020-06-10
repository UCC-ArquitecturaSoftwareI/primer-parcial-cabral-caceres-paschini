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

        scrollingBack -= 0.5f;
        if (scrollingBack <= -Background.width * 2) scrollingBack = 0;

        BeginDrawing();
        DrawTextureEx(Background, (Vector2) {scrollingBack, 0}, 0.0f, 2.0f, WHITE);
        DrawTextureEx(Background, (Vector2) {Background.width * 2 + scrollingBack, 0}, 0.0f, 2.0f, WHITE);
        EndDrawing();
    }
}