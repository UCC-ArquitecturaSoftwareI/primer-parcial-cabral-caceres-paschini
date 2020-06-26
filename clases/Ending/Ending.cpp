#include "Ending.h"
#include <iostream>

Ending::Ending() {
    Background = LoadTexture("../resources/Menu/Back_menu.png");
    Back_ = {250, 100, 600, 400};
    Button1 = {340, 430, 150, 40};
    Button2 = {580, 430, 150, 40};
    Mouse = {GetMousePosition().x, GetMousePosition().y, 20, 20};
    Result = false;
    Sec = "55";
    Min = "15";
    GoTo = 0;
}

void Ending::Update_End() {
    if (Result) {
        Srend = new Sound_Render("../resources/Music/Winner.mp3");
    } else {
        Srend = new Sound_Render("../resources/Music/loser.mp3");
    }
    Srend->PlayMusic();
    while (GoTo == 0) {
        Draw();
        Detect_Input();
        Srend->UpdateMusic();
    }
}

void Ending::Detect_Input() {
    Mouse = {GetMousePosition().x, GetMousePosition().y, 20, 20};
    if (IsKeyDown(KEY_EIGHT)) {
        Srend->ChangeVolume(0.01);
    }
    if (IsKeyDown(KEY_TWO)) {
        Srend->ChangeVolume(-0.01);
    }
    if (IsMouseButtonDown(MOUSE_LEFT_BUTTON) && CheckCollisionRecs(Button1, Mouse))
        GoTo = 1;
    if (IsMouseButtonDown(MOUSE_LEFT_BUTTON) && CheckCollisionRecs(Button2, Mouse))
        GoTo = 2;
}

void Ending::Draw() {
    scrollingBack -= 0.5f;
    if (scrollingBack <= -Background.width * 2) scrollingBack = 0;

    BeginDrawing();
    DrawTextureEx(Background, (Vector2) {scrollingBack, 0}, 0.0f, 2.0f, WHITE);
    DrawTextureEx(Background, (Vector2) {Background.width * 2 + scrollingBack, 0}, 0.0f, 2.0f, WHITE);

    DrawRectangleRounded(Back_, .5, 1, BLACK);
    DrawRectangleRoundedLines(Back_, .5, 1, 3, WHITE);
    DrawRectangleRounded(Button1, .5, 1, WHITE);
    DrawRectangleRoundedLines(Button1, .5, 1, 3, BLACK);
    DrawRectangleRounded(Button2, .5, 1, WHITE);
    DrawRectangleRoundedLines(Button2, .5, 1, 3, BLACK);
    DrawLineEx({385, 215}, {700, 215}, 3, WHITE);

    const char *S = nullptr;
    S = Sec.c_str();

    const char *M = nullptr;
    M = Min.c_str();

    DrawText("Final Time: ", 340, 250, 30, WHITE);
    DrawText("M,", 545, 250, 30, WHITE);
    DrawText("S", 630, 250, 30, WHITE);
    DrawText("Menu", 370, 435, 30, BLACK);
    DrawText("Play", 620, 435, 30, BLACK);


    DrawText("Thanks for Playing", 330, 120, 40, WHITE);

    if (Result) {
        DrawText("Congrats!", 460, 180, 30, WHITE);
        DrawText(M, 510, 250, 30, LIME);
        DrawText(S, 585, 250, 30, LIME);
    } else {
        DrawText("Try Again!", 450, 180, 30, WHITE);
        DrawText(M, 510, 250, 30, RED);
        DrawText(S, 585, 250, 30, RED);
    }
    EndDrawing();
}

void Ending::On() {
    Update_End();

}

int Ending::Off() {
    return GoTo;
}

void Ending::LoadState(bool w, Vector2 vec) {
    Result = w;
    int s =vec.y;
    int m =vec.x;
    Min = std::to_string(m);
    Sec = std::to_string(s);
}
