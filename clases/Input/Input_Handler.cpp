//
// Created by martin on 9/5/20.
//

#include "Input_Handler.h"


Input_Handler::Input_Handler(Player *Ch) {
    Play = Ch;
    KeyPress.x = 0;
    KeyPress.y = 0;
    CanJump = true;
}


/**
 * Keypress
 * Direction = 0 right/ 1 left
 */
void Input_Handler::setKeyPress() {

    float Acc_x = 0.3;
    float Acc_y = 5;
    KeyPress.x = 5;

    if (IsKeyDown(KEY_RIGHT)) {
        KeyPress.x = 7;
        KeyPress.y = 0;
        Play->Acelerate_x(Acc_x);
    }
    if (IsKeyDown(KEY_LEFT)) {
        KeyPress.x = 7;
        KeyPress.y = 1;
        Play->Acelerate_x(-Acc_x);
    }
    if (IsKeyDown(KEY_UP) && CanJump) {
        KeyPress.x = 3;
        Play->Jump_y(Acc_y);
    }
}

int Input_Handler::GetCharStatus() {
    int a = KeyPress.x + KeyPress.y;
    return a;
}

void Input_Handler::GetCanJump(bool can) {
    if (!can)
        KeyPress.x = 3;
    CanJump = can;
}




