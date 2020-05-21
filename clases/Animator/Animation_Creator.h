//
// Created by martin on 20/5/20.
//

#ifndef RAYLIBTEMPLATE_ANIMATION_CREATOR_H
#define RAYLIBTEMPLATE_ANIMATION_CREATOR_H

#include <vector>
#include "../Fruits/Fruits.h"
#include "Image_Holder.h"

class Animation_Creator {
public:
    void Create(std::vector<Entity *> *Vector_file);

    void Create(std::vector<Fruits *> *Vector_file);

    void Create(Entity *Ent);

};


#endif //RAYLIBTEMPLATE_ANIMATION_CREATOR_H