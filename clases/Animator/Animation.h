//
// Created by Martin on 26/04/2020.
//

#ifndef RAYLIBTEMPLATE_ANIMATION_H
#define RAYLIBTEMPLATE_ANIMATION_H

#include <string>
#include "raylib.h"
#include <vector>
#include <fstream>
#include <unistd.h>
#include <iostream>
#include "Image_Holder.h"

class Animation {
private:
    int currentRow;
    int currentColumn;
    Image_Holder *image;
    Rectangle frameRec{};
public:
    Animation(Image_Holder *img);

    void Animate(Vector2 pos);

    void Animte_Still(Vector2 pos);

    void setCurrentRow(int currentRow);

};


#endif //RAYLIBTEMPLATE_ANIMATION_H
