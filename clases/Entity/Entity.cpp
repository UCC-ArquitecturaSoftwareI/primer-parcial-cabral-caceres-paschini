//
// Created by martin on 20/5/20.
//

#include "Entity.h"

Entity::Entity() {
    filePathText = "resources/level/Missing.jpg";
    Entity_pos = {100, 100};
    maxCol = {0, 0};
    Ani = nullptr;
}

Entity::Entity(std::string file, Vector2 pos, std::vector<int> Max_Col, Vector2 Prop) {
    filePathText = file;
    Entity_pos = pos;
    maxCol = Max_Col;
    Ani = nullptr;
    Proportion = Prop;
}

void Entity::Set_x(float d) {
    Entity_pos.x = d;
}

void Entity::Set_y(float d) {
    Entity_pos.y = d;
}

Vector2 &Entity::Get_Entity_Pos() {
    return Entity_pos;
}


const std::string &Entity::GetFilePathText() const {
    return filePathText;
}

const std::vector<int> &Entity::GetMaxCol() const {
    return maxCol;
}

void Entity::Assign_Animator(Animation *Animator) {
    Ani = Animator;
}

Animation *Entity::GetAni() const {
    return Ani;
}

const Vector2 &Entity::GetProportion() const {
    return Proportion;
}

void Entity::Animate() {
    Ani->Animate(Entity_pos);
}

void Entity::Set_Animation(int Temp) {
    Ani->setCurrentRow(Temp);
}

