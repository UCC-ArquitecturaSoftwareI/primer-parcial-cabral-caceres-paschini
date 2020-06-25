#include "Menu.h"
#include <iostream>


Menu::Menu() {


    Background = LoadTexture("../resources/Menu/Back_menu.png");
    Back_ = {250, 100, 600, 400};
    Button = {450, 560, 200, 40};
    Mouse = {GetMousePosition().x, GetMousePosition().y, 20, 20};
    Srend = new Sound_Render("resources/Music/Menu.mp3");
    Goto = 0;

}

void Menu::Update_Menu() {
    Srend->PlayMusic();
    while (Goto == 0) {
        Draw();
        Srend->UpdateMusic();
        Goto = Detect_Input();
    }
}

int Menu::Detect_Input() {
    Mouse = {GetMousePosition().x, GetMousePosition().y, 20, 20};
    if (IsKeyDown(KEY_U)) {
        Srend->ChangeVolume(0.01);
    }
    if (IsKeyDown(KEY_D)) {
        Srend->ChangeVolume(-0.01);
    }
    if (IsMouseButtonDown(MOUSE_LEFT_BUTTON) && CheckCollisionRecs(Button, Mouse))
        return 2;
}

void Menu::Draw() {
    scrollingBack -= 0.5f;
    if (scrollingBack <= -Background.width * 2) scrollingBack = 0;

    BeginDrawing();
    DrawTextureEx(Background, (Vector2) {scrollingBack, 0}, 0.0f, 2.0f, WHITE);
    DrawTextureEx(Background, (Vector2) {Background.width * 2 + scrollingBack, 0}, 0.0f, 2.0f, WHITE);

    DrawRectangleRounded(Back_, .5, 1, BLACK);
    DrawRectangleRoundedLines(Back_, .5, 1, 3, WHITE);
    DrawRectangleRounded(Button, .5, 1, WHITE);
    DrawRectangleRoundedLines(Button, .5, 1, 3, BLACK);


    DrawText("Bienvenidos al PLAt_", 330, 120, 40, WHITE);
    DrawText("Haz Click para jugar", 385, 180, 30, WHITE);
    DrawLineEx({385, 215}, {700, 215}, 3, WHITE);
    DrawText(" \tCreado por: \n-Caceres Martin\n-Cabral Camila\n-Paschini Catalina", 385, 250, 30, WHITE);
    DrawText("PLAY", 510, 568, 30, BLACK);
    DrawText("'U' for volume up \n'D' for volume down", 20, 623, 20, BLACK);
    EndDrawing();
}

void Menu::On() {
    Update_Menu();

}

int Menu::Off() {
    return Goto;
}

Menu::~Menu() {
    delete Srend;
}

