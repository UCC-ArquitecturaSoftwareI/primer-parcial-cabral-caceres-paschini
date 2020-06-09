//
// Created by martin on 21/5/20.
//

#include "All_entity.h"

All_entity::All_entity() { All_Ent.empty(); }

void All_entity::Add_entity(Entity *Ent) {
    All_Ent.push_back(Ent);
}

void All_entity::Add_entity(std::vector<Enemies *> *Vec) {
    for (auto i: *Vec) {
        All_Ent.push_back(i);
    }
}

void All_entity::Add_entity(std::vector<Fruits *> *Vec) {
    for (auto i: *Vec) {
        All_Ent.push_back(i);
    }
}

std::vector<Entity *> *All_entity::Get_Entities() {
    return &All_Ent;
}

void All_entity::Call_Ani() {
    for (auto i:All_Ent){
        i->Animate();
    }
}
