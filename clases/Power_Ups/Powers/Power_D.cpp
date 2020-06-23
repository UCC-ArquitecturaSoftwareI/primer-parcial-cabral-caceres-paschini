//
// Created by martin on 23/6/20.
//

#include "Power_D.h"

Power_D::Power_D(Character *Pla) {
    Player = Pla;
    Timer = 300;
    Type = 5;
    Img = new Image_Holder({7, 7, 7, 7, 7, 7, 7, 3}, "resources/Effects/Purple_Fire.v2.png", {64, 64});
    Sound S = LoadSound("resources/Music/Time_Stop.mp3");
    PlaySound(S);
}

void Power_D::Activate_Power() {

}
