#include "Power_E.h"

Power_E::Power_E(Character *Pla) {
    Type = 6;
    Player = Pla;
    Timer = 300;
    Img = new Image_Holder({7, 7, 7, 7, 7, 7, 7, 3}, "resources/Effects/Red_fire.v2.png", {64, 64});
    Player->SetSpdMulti(1.5);
    Player->Set_MaxSpeed(5);
}

void Power_E::Activate_Power() {

}
