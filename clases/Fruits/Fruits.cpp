#include "Fruits.h"

bool Fruits::Is_picked() {
    return picked_up;
}

int Fruits::Get_points() {
    return points;
}

Fruits::~Fruits() = default;
