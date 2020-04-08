//
// Created by Martin on 08/04/2020.
//

#include "Background.h"

Background::Background(std::string text) {
    Map =LoadTexture(text.c_str());
}

void Background::draw() {
    DrawTexture(Map,0,0,WHITE);
}