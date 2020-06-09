//
// Created by martin on 7/6/20.
//

#include "Slime.h"

void Slime::move_x() {
    switch (State_x) {
        case 1:
            if (Idle_Counter <= 70) {
                Idle_Counter++;
                Set_Animation(1);
            } else {
                Idle_Counter = 0;
                State_x = -2;
                Set_Animation(0);
            }
            return;
        case -1:
            if (Idle_Counter <= 70) {
                Idle_Counter++;
                Set_Animation(0);
            } else {
                Idle_Counter = 0;
                State_x = 2;
                Set_Animation(1);
            }
            return;
        case 2:
            Entity_pos.x += 2.5;
            return;
        case -2:
            Entity_pos.x -= 2.5;
            return;
    }
}

void Slime::move_y() {}

