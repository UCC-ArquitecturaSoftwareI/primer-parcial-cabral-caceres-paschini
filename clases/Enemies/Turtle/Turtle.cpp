//
// Created by martin on 7/6/20.
//

#include "Turtle.h"

void Turtle::move_x() {
    switch (State_x) {
        case 1:
            if (Idle_Counter <= 85) {
                Idle_Counter++;
                Set_Animation(5);
            } else {
                Idle_Counter = 0;
                State_x = -2;
                Set_Animation(7);
            }
            return;
        case -1:
            if (Idle_Counter <= 85) {
                Idle_Counter++;
                Set_Animation(7);
            } else {
                Idle_Counter = 0;
                State_x = 2;
                Set_Animation(5);
            }
            return;
        case 2:
            Entity_pos.x += 2;
            return;
        case -2:
            Entity_pos.x -= 2;
            return;
    }
}

void Turtle::move_y() {

}
