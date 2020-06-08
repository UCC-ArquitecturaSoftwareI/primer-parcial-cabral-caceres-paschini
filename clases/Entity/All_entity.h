//
// Created by martin on 21/5/20.
//

#ifndef RAYLIBTEMPLATE_ALL_ENTITY_H
#define RAYLIBTEMPLATE_ALL_ENTITY_H


#include "Entity.h"
#include "../Fruits/Fruits.h"

class All_entity {
private:
    std::vector<Entity*> All_Ent;
public:
    All_entity();

    void Add_entity(Entity * Ent);

    void Add_entity(std::vector<Entity *> *Vec);

    void Add_entity(std::vector<Fruits *> *Vec);

    std::vector<Entity *> *Get_Entities();

    void Call_Ani();
};


#endif //RAYLIBTEMPLATE_ALL_ENTITY_H
