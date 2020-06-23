//
// Created by martin on 23/6/20.
//

#ifndef RAYLIBTEMPLATE_POWER_UPS_H
#define RAYLIBTEMPLATE_POWER_UPS_H

#include "../Animator/Image_Holder.h"
#include <vector>
#include "../Animator/Animation.h"
#include "../Character/Character.h"

class Power_Ups {
protected:
    Image_Holder *Img{};
    Character *Player;
    int Timer;
    int Type;
public:
    Power_Ups();

    Image_Holder *Get_Img();

    virtual void Activate_Power() = 0;

    ~Power_Ups();

    int Return_Timer();

    void Reduce_timer();

    int Return_Type();
};


#endif //RAYLIBTEMPLATE_POWER_UPS_H
