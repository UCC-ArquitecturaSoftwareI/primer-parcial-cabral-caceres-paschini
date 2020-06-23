//
// Created by martin on 20/5/20.
//

#ifndef RAYLIBTEMPLATE_ANIMATION_CREATOR_H
#define RAYLIBTEMPLATE_ANIMATION_CREATOR_H

#include <vector>
#include "../Fruits/Fruits.h"
#include "Image_Holder.h"
#include "unordered_map"

class Animation_Creator {
    std::unordered_map<std::string , Image_Holder*>  Map;
public:
    void Create(std::vector<Entity *> *Vector_file);
};


#endif //RAYLIBTEMPLATE_ANIMATION_CREATOR_H
