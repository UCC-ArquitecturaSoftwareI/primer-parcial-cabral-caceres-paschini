//
// Created by martin on 8/6/20.
//

#include "GUI.h"

void GUI::DrawGui(int Amount) {


    Fruis_left = std::to_string(Amount);
    const char *c = nullptr;
    c = Fruis_left.c_str();

    Sec = std::to_string(Seconds);
    const char *S = nullptr;
    S = Sec.c_str();

    Min = std::to_string(Minutes);
    const char *M = nullptr;
    M = Min.c_str();


    DrawRectangleRoundedLines(Rec_1, 30, 2, 3, BLACK);
    DrawRectangleRounded(Rec_1, 30, 2, BEIGE);
    DrawRectangleRoundedLines(Rec_2, 30, 2, 3, BLACK);
    DrawRectangleRounded(Rec_2, 30, 2, BEIGE);
    DrawRectangleRoundedLines(Rec_3, 30, 2, 3, BLACK);
    DrawRectangleRounded(Rec_3, 30, 2, BEIGE);

    DrawText("Time: ", 20, 20, 20, BLACK);
    DrawText(M, 70, 20, 20, BLACK);
    DrawText("m: ", 83, 20, 20, BLACK);
    DrawText(S, 103, 20, 20, BLACK);
    DrawText("s", 130, 20, 20, BLACK);
    DrawText("life: ", 20, 40, 20, BLACK);
    DrawText("Fruits: ", 920, 20, 20, BLACK);
    DrawText(c, 1000, 20, 20, BLACK);
    DrawText("/35", 1030, 20, 20, BLACK);
    DrawText("'U' for volume up \n'D' for volume down", 20, 623, 20, BLACK);

    if (Amount != 0) {
        Take_Time();
    }
    Player->SetMin(Minutes);
    Player->SetSec(Seconds);

}

GUI::GUI() {
    Rec_1 = {5, 15, 180, 50};
    Rec_2 = {910, 15, 180, 30};
    Rec_3 = {5, 620, 250, 55};
    Seconds = Minutes = timer = 0;
}

void GUI::Take_Time() {
    if (timer == 60) {
        Seconds++;
        timer = 0;
    } else
        timer++;
    if (Seconds == 60) {
        Seconds = 0;
        Minutes++;
    }
}

void GUI::LoadPlayer(Character *Play) {
    Player = Play;
}


