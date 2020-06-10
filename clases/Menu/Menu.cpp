//
// Created by Catalina on 27/05/2020.
//

#include <string>
#include "Menu.h"

Menu::Menu( ) {

    InitWindow( 1104, 688, "raylib - Plataformer");
    Background= LoadTexture("../resources/Menu/back_menu.png");
    Rec_Menu = {480, 500, 180, 70};
}

void Menu::Draw() {
    scrollingBack -= 0.2f;
    if (scrollingBack <= -Background.width * 2) scrollingBack = 0;

    BeginDrawing();
    DrawTextureEx(Background, (Vector2) {scrollingBack, 0}, 0.0f, 2.0f, WHITE);
    DrawTextureEx(Background, (Vector2) {Background.width * 2 + scrollingBack, 0}, 0.0f, 2.0f, WHITE);
    DrawRectangleRoundedLines(Rec_Menu, 30, 2, 3, BLACK);
    DrawRectangleRounded(Rec_Menu, 30, 2, BEIGE);
    DrawText("PLAY", 520, 520, 40, BLACK);
    DrawText("¡WELCOME!", 300, 300, 100, BLACK);
    EndDrawing();
}
