//
// Created by martin on 8/6/20.
//

#include "Enemies.h"

int Enemies::Get_State_x() {
    return State_x;
}

int Enemies::Get_State_y() {
    return State_y;
}

int Enemies::Get_Counter() {
    return Idle_Counter;
}

void Enemies::Set_Sate_x(int s) {
    State_x = s;
}

void Enemies::Set_Sate_y(int s) {
    State_y = s;
}