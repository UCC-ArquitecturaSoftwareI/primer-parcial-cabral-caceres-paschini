#include "Player_Decorator.h"

Player_Decorator::Player_Decorator(Character *chara) {
    Player = chara;
    srand(time(0));
    Cu_Power = (rand() % 5) + 1;
    switch (Cu_Power) {
        case 1: {
            Power_A *pa;
            pa = new Power_A(Player);
            Power = pa;
            break;
        }
        case 2: {
            Power_B *pb;
            pb = new Power_B(Player);
            Power = pb;
            break;
        }
        case 3: {
            Power_C *pc;
            pc = new Power_C(Player);
            Power = pc;
            break;
        }
        case 4: {
            Power_D *pd;
            pd = new Power_D(Player);
            Power = pd;
            break;
        }
        case 5: {
            Power_E *pe;
            pe = new Power_E(Player);
            Power = pe;
            break;
        }
        default:
            throw 404;
    }

    Ani = new Animation(Power->Get_Img());
}

void Player_Decorator::DrawFx() {
    Ani->Animate({Player->Get_Entity_Pos().x - 16, Player->Get_Entity_Pos().y - 32});
}

bool Player_Decorator::Get_Timer() {
    return Power->Return_Timer() < 0;
}

void Player_Decorator::Reduce_Timer() {
    Power->Reduce_timer();
}

Player_Decorator::~Player_Decorator() {
    delete Power;
    delete Ani;
}

void Player_Decorator::Activate_Power() {
    Power->Activate_Power();
}

int Player_Decorator::Get_Type() {
    return Power->Return_Type();
}

