//
// Created by Catalina on 27/05/2020.
//

#include "Menu.h"
#include <iostream>


Menu::Menu() {


    Background = LoadTexture("../resources/Menu/Back_menu.png");
    Back_ = {250, 40, 600, 400};
    Button = {450, 380, 200, 40};
    Mouse = {GetMousePosition().x, GetMousePosition().y, 20, 20};
    Srend = new Sound_Render("resources/Music/Menu.mp3");
    WASD = LoadTexture("resources/Menu/keys-transparent-wasd-1.png");
    RED_Fire = LoadTexture("resources/Menu/Red.png");
    BLUE_Fire = LoadTexture("resources/Menu/Blue.png");
    PINK_Fire = LoadTexture("resources/Menu/Pink.png");
    PURPLE_Fire = LoadTexture("resources/Menu/Purple.png");
    GREEN_Fire = LoadTexture("resources/Menu/Green.png");
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
    if (IsKeyDown(KEY_EIGHT)) {
        Srend->ChangeVolume(0.01);
    }
    if (IsKeyDown(KEY_TWO)) {
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


    DrawText("Bienvenidos al PLAt_", 330, 60, 40, WHITE);
    DrawText("Haz Click para jugar", 385, 120, 30, WHITE);
    DrawLineEx({385, 155}, {700, 155}, 3, WHITE);
    DrawText(" \tCreado por: \n-Caceres Martin\n-Cabral Camila\n-Paschini Catalina", 385, 170, 30, WHITE);
    DrawText("PLAY", 510, 385, 30, BLACK);
    DrawText("Use W,A,S,D to move", 20, 655, 25, BLACK);
    DrawText("'8' for volume up \n'2' for volume down", 20, 20, 20, BLACK);
    DrawText("if you eat 3 fruits, you'll get a random effect", 320, 450, 20, BLACK);


    DrawTextureEx(WASD, {20, 480,}, 1, .9, WHITE);
    DrawTextureEx(RED_Fire, {400, 450,}, 1, 1, WHITE);
    DrawText("Move Fast", 380, 520, 20, BLACK);
    DrawTextureEx(BLUE_Fire, {650, 520,}, 1, 1, WHITE);
    DrawText("Stop Time", 630, 590, 20, BLACK);
    DrawTextureEx(PINK_Fire, {900, 450,}, 1, 1, WHITE);
    DrawText("Gain 1 Life", 880, 520, 20, BLACK);
    DrawTextureEx(GREEN_Fire, {400, 580,}, 1, 1, WHITE);
    DrawText("Move Slow", 380, 650, 20, BLACK);
    DrawTextureEx(PURPLE_Fire, {900, 580,}, 1, 1, WHITE);
    DrawText("Stop Time", 880, 650, 20, BLACK);
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

