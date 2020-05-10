//
// Created by martin on 9/5/20.
//

#include "Input_Handler.h"


Input_Handler::Input_Handler(Player *Ch) {
    Play = Ch;
    KeyPress.x = 0;
    KeyPress.y = 0;
}


/**
 * Keypress
 * Direction = 0 right/ 1 left
 */
void Input_Handler::setKeyPress() {

    KeyPress.x = 5;

    if (IsKeyDown(KEY_RIGHT)) {
        KeyPress.x = 7;
        Play->move_x(2);
        KeyPress.y = 0;
    }
    if (IsKeyDown(KEY_LEFT)) {
        KeyPress.x = 7;
        Play->move_x(-2);
        KeyPress.y = 1;
    }
    if (IsKeyDown(KEY_UP)) {
        KeyPress.x = 3;
        Play->jump_y();
    }
}

 Vector2 &Input_Handler::getKeyPress() {
    return KeyPress;
}

int Input_Handler::GetCharStatus() {
    int i = KeyPress.x + KeyPress.y;
    return i;
}




