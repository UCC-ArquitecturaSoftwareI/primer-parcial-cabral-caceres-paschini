//
// Created by Camila Cabral on 28/04/2020.
//

#include <iostream>
#include "Fruta.h"
/*Fruta::Fruta(int lvl, const Vector2 &fruta_posicion,std::string patch ) {
level=lvl;
if(lvl==1)
{

}
}*/
void Fruta::draw() {

}

Fruta::Fruta(const Vector2 &frutaPosition, int tipo) : fruta_position(frutaPosition), tipo(tipo) {

}

void Fruta::move_x(float d) {
  fruta_position.x += d;
}

void Fruta::move_y(float d) {
    fruta_position.y+= d;
}