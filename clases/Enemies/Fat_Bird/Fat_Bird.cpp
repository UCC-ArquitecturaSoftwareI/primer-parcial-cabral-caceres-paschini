#include "Fat_Bird.h"

void Fat_Bird::move_y() {
    switch (State_y) {
        case 1:
            if (Idle_Counter <= 70) {
                Idle_Counter++;
                Set_Animation(1);
            } else {
                Idle_Counter = 0;
                State_y = 2;
                Set_Animation(2);
            }
            return;
        case -1:
            if (Idle_Counter <= 30) {
                Idle_Counter++;
                Set_Animation(2);
            } else {
                Idle_Counter = 0;
                State_y = -2;
                Set_Animation(0);
            }
            return;
        case 2:
            Entity_pos.y -= 1;
            return;
        case -2:
            Entity_pos.y += 5;
            return;
    }
}

void Fat_Bird::move_x() {}
