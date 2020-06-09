
// Created by martin on 21/5/20.
//

#include "Fruit_Vector.h"

Fruit_Vector::Fruit_Vector(std::vector<Vector2> Pos_fruits) {
    for (auto i : Pos_fruits) {
        Fruits *Fruit_a;
        Fruit_a = new Fruits("resources/level/Fruits.png",i,{16,16,16,16,16,16,16,16,3});
        Amount++;
        Fruits_Vec.push_back(Fruit_a);
    }
}

std::vector<Fruits *> *Fruit_Vector::Get_Vec_pointer() {
    return &Fruits_Vec;
}

void Fruit_Vector::Set_fruit_type() {
    for(auto i: Fruits_Vec){
        i->GetAni()->setCurrentRow(i->Get_points()/100);
    }
}

void Fruit_Vector::Call_Animator() {
    for(auto i :Fruits_Vec){
        i->GetAni()->Animate(i->Get_Entity_Pos());
    }
}

void Fruit_Vector::Delete_fruit() {
Amount--;
}

int Fruit_Vector::Get_Amount() {
    return Amount;
}


