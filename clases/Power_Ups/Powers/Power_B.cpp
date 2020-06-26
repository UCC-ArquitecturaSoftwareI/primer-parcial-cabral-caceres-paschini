#include "Power_B.h"

Power_B::Power_B(Character *Pla) {
    Type = 2;
    Player = Pla;
    Timer = 150;
    Img = new Image_Holder({7, 7, 7, 7, 7, 7, 7, 3}, "resources/Effects/Green_fire.v2.png", {64, 64});
    Player->SetSpdMulti(.5);
    Player->Set_MaxSpeed(2);
}

void Power_B::Activate_Power() {

}
