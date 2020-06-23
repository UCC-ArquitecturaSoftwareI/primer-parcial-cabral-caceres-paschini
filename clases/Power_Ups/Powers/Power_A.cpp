//
// Created by martin on 23/6/20.
//

#include "Power_A.h"

Power_A::Power_A(Character *Pla) {
    Type = 1;
    Player = Pla;
    Timer = 150;
    Img = new Image_Holder({7,7,7,7,7,7,7,3},"resources/Effects/Blue_Fire.v2.png",{64,64});
}

void Power_A::Activate_Power() {
    Player->Setspeed_y(-1.8);
}

