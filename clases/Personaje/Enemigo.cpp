//
// Created by Camila Cabral on 25/04/2020.
//

#include <string>
#include "Enemigo.h"

Enemigo::Enemigo(std::string file, const Vector2 &enemPos) : enemigo_pos(enemPos) {

    enemigo = LoadTexture(file.c_str());
}

void Enemigo::draw() {
    DrawTexture(enemigo, enemigo_pos.x - enemigo.width/2, enemigo_pos.y- enemigo.height/2, WHITE);
}
void Enemigo::move_x(float d) {
    enemigo_pos.x += d;
}

void Enemigo::move_y(float d) {
    enemigo_pos.y += d;
}
Vector2 &Enemigo::getEnemigoPos() {
    return enemigo_pos;
}
/*
Texture2D &Enemigo::getEnemigoText()  {
    return enemigo_text;
}*/
