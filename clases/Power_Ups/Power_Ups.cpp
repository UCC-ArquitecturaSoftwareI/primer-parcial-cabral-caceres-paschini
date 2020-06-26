#include "Power_Ups.h"

Power_Ups::Power_Ups() {

}

Image_Holder *Power_Ups::Get_Img() {
    return Img;
}

Power_Ups::~Power_Ups() {
    delete Img;
}

int Power_Ups::Return_Timer() {
    return Timer;
}

void Power_Ups::Reduce_timer() {
    Timer--;
}

int Power_Ups::Return_Type() {
    return Type;
}
