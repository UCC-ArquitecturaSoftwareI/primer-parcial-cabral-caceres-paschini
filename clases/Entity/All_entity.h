//
// Created by martin on 21/5/20.
//

#ifndef RAYLIBTEMPLATE_ALL_ENTITY_H
#define RAYLIBTEMPLATE_ALL_ENTITY_H


#include "Entity.h"
#include "../Fruits/Fruits.h"
#include <unordered_map>

class All_entity {
private:
    //std::unordered_map<std::string,>
public:
    All_entity();

    void Add_entity(Entity * Ent);

    void Add_entity(std::vector<Entity *> *Vec);

    void Add_entity(std::vector<Fruits *> *Vec);

    std::vector<Entity *> *Get_Entities();
};


#endif //RAYLIBTEMPLATE_ALL_ENTITY_H
