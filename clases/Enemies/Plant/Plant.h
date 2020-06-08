//
// Created by martin on 7/6/20.
//

#ifndef RAYLIBTEMPLATE_PLANT_H
#define RAYLIBTEMPLATE_PLANT_H

#include "../../Entity/Entity.h"

class Plant : public Entity {
    private:
    public:
        Plant(std::string file, Vector2 playpos) : Entity(std::move(file), playpos,{7,7,10,10},Vector2{44, 42}) {}

};


#endif //RAYLIBTEMPLATE_PLANT_H
