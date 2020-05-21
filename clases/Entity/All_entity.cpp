//
// Created by martin on 21/5/20.
//

#include "All_entity.h"


void All_entity::Add_entity(Entity *Ent) {
    All_ent.push_back(Ent);
}

void All_entity::Add_entity(std::vector<Entity *> *Vec) {
    for (auto i : *Vec) {
        All_ent.push_back(i);
    }
}

void All_entity::Add_entity(std::vector<Fruits *> *Vec) {
    for (auto i : *Vec) {
        All_ent.push_back(i);
    }
}

std::vector<Entity *> *All_entity::Get_Entities() {
    return &All_ent;
}

All_entity::All_entity() = default;
