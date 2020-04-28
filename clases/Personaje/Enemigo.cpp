//
// Created by Camila Cabral on 25/04/2020.
//

#include <string>
#include "Enemigo.h"

Enemigo::Enemigo(std::string file, const Vector2 &enempos) : enemigo_pos(enempos) {

    enemigo_text = LoadTexture(file.c_str());
}


void Enemigo::move_x(float d) {
    enemigo_pos.x += d;
}
void Enemigo::move_y(float d) {
    enemigo_pos.y += d;
}

Texture2D &Enemigo::getEnemigoText() {
    return enemigo_text;
}
void Enemigo::draw() {
    DrawTexture(enemigo_text, enemigo_pos.x - enemigo_text.width/2, enemigo_pos.y- enemigo_text.height/2, WHITE);
}
