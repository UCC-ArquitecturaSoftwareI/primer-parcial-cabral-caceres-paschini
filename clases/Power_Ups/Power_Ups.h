//
// Created by martin on 23/6/20.
//

#ifndef RAYLIBTEMPLATE_POWER_UPS_H
#define RAYLIBTEMPLATE_POWER_UPS_H

#include "../Animator/Image_Holder.h"
#include <vector>
#include "../Animator/Animation.h"

class Power_Ups {
protected:
    Image_Holder *Img{};
public:
    Power_Ups();

    Image_Holder *Get_Img();

    ~Power_Ups();
};


#endif //RAYLIBTEMPLATE_POWER_UPS_H
