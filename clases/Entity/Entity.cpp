//
// Created by martin on 20/5/20.
//

#include "Entity.h"

Entity::Entity() {
    filePathText = "resources/level/Missing.jpg";
    Entity_pos = {100, 100};
    maxCol = {0, 0};
}

Entity::Entity(std::string file, Vector2 pos, std::vector<int> Max_Col) {
    filePathText = file;
    Entity_pos = pos;
    maxCol = Max_Col;
}

void Entity::Set_x(float d) {
    Entity_pos.x = d;
}

void Entity::Set_y(float d) {
    Entity_pos.y = d;
}

Vector2 &Entity::get_Entity_Pos() {
    return Entity_pos;
}

Entity::~Entity() {

}
