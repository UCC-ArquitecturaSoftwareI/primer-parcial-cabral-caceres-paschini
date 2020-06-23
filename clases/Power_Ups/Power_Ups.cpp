//
// Created by martin on 23/6/20.
//

#include "Power_Ups.h"

Power_Ups::Power_Ups() {

}

Image_Holder *Power_Ups::Get_Img() {
    return Img;
}

Power_Ups::~Power_Ups() {
    delete Img;
}
