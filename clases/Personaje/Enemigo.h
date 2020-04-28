//
// Created by Camila Cabral on 25/04/2020.
//

#ifndef PRIMER_PARCIAL_CABRAL_CACERES_PASCHINI_CAMI_ENEMIGO_H
#define PRIMER_PARCIAL_CABRAL_CACERES_PASCHINI_CAMI_ENEMIGO_H
#include <raylib.h>
#include <string>

class Enemigo {
private:
    Texture2D enemigo_text;
    Vector2 enemigo_pos;
public:
    Enemigo(std::string file, const Vector2 &enempos);
    void move_x(float d);
    void move_y(float d);
    void draw();

    Texture2D &getEnemigoText();
};
#endif //PRIMER_PARCIAL_CABRAL_CACERES_PASCHINI_CAMI_ENEMIGO_H
