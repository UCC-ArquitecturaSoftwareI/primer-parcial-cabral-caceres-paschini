#include "Power_C.h"

Power_C::Power_C(Character *Pla) {
    Type = 3;
    Player = Pla;
    Img = new Image_Holder({7, 7, 7, 7, 7, 7, 7, 3}, "resources/Effects/Pink_Fire.v2.png", {64, 64});
    Timer = 150;
    if (Player->Get_life_Num() < 3)
        Player->Change_life(1);
}

void Power_C::Activate_Power() {
}
