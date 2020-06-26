#include "Collision.h"

Collision::Collision() {
    Fruit_area = {0, 0, 16, 16};
}

void Collision::Load_Vector(std::vector<Fruits *> *vec) {
    Fruits_Vec = vec;
}

void Collision::Load_Vector(std::vector<Rectangle> *vec, int Dat) {
    switch (Dat) {
        case 0:
            Floor_Wall = vec;
            return;
        case 1:
            Plataform = vec;
            return;
        case 2:
            Traps = vec;
            return;
        default:
            std::cout << "Lista incorrecta" << std::endl;
            return;
    }
}


bool Collision::IsColliding_X(Character *Ent) {

    Ent_Rec = {Ent->Get_Entity_Pos().x, Ent->Get_Entity_Pos().y, Ent->GetProportion().x, Ent->GetProportion().y};

    for (auto &i: *Floor_Wall) {
        if (CheckCollisionRecs(Ent_Rec, i)) {

            if (Ent->GetSpeed().x > 0) {
                Ent->Set_x(i.x - Ent_Rec.width - 1);
                Ent->Setspeed_x(0);
                return true;
            }

            if (Ent->GetSpeed().x < 0) {
                Ent->Set_x(i.x + i.width);
                Ent->Setspeed_x(0);
                return true;
            }

        }
    }
    return false;
}

bool Collision::IsColliding_X(Enemies *Ent) {
    Ent_Rec = {Ent->Get_Entity_Pos().x, Ent->Get_Entity_Pos().y, Ent->GetProportion().x, Ent->GetProportion().y};

    for (auto &i: *Floor_Wall) {
        if (CheckCollisionRecs(Ent_Rec, i)) {

            if (Ent->Get_State_x() == 2) {
                Ent->Set_x(i.x - Ent_Rec.width - 1);
                Ent->Set_Sate_x(1);
                return true;
            }

            if (Ent->Get_State_x() == -2) {
                Ent->Set_x(i.x + i.width + 1);
                Ent->Set_Sate_x(-1);
                return true;
            }

        }
    }
    return false;
}

bool Collision::IsColliding_y(Enemies *Ent) {
    Ent_Rec = {Ent->Get_Entity_Pos().x, Ent->Get_Entity_Pos().y, Ent->GetProportion().x, Ent->GetProportion().y};

    for (auto &i: *Floor_Wall) {
        if (CheckCollisionRecs(Ent_Rec, i)) {

            if (Ent->Get_State_y() == 2) {
                Ent->Set_Sate_y(-1);
                Ent->Set_y(i.y + i.height + 1);
                return true;
            }

            if (Ent->Get_State_y() == -2) {
                Ent->Set_Sate_y(1);
                Ent->Set_y(i.y - Ent_Rec.height - 1);
                return true;
            }
        }
    }
    return false;
}


bool Collision::IsColliding_y(Character *Ent) {

    Ent_Rec = {Ent->Get_Entity_Pos().x, Ent->Get_Entity_Pos().y, Ent->GetProportion().x,
               Ent->GetProportion().y};

    for (auto &i: *Floor_Wall) {
        if (CheckCollisionRecs(Ent_Rec, i)) {


            if (Ent->GetSpeed().y > 0) {
                Ent->Set_y(i.y - Ent_Rec.height - 1);
                Ent->Setspeed_y(0);
                return true;
            } else {
                Ent->Set_y(i.y + i.height + 1);
                Ent->Setspeed_y(0.2);
                return true;
            }
        }
    }
    return false;
}

bool Collision::IsCollidingPlataform(Character *Ent) {

    Ent_Rec = {Ent->Get_Entity_Pos().x, Ent->Get_Entity_Pos().y, Ent->GetProportion().x,
               Ent->GetProportion().y};

    for (auto &i: *Plataform) {
        if (CheckCollisionRecs(Ent_Rec, i))
            if (Ent_Rec.y + Ent_Rec.height > i.y && Ent->GetSpeed().y > 0) {
                Ent->Set_y(i.y - Ent_Rec.height - 1);
                Ent->Setspeed_y(0);
                return true;
            }
    }
    return false;
}

bool Collision::IsFlying(Character *Ent) {

    Ent_Rec = {Ent->Get_Entity_Pos().x + 7, Ent->Get_Entity_Pos().y, 25, 34};

    for (auto &i: *Floor_Wall) {
        if (CheckCollisionRecs(Ent_Rec, i))
            return false;
    }

    for (auto &i: *Plataform) {
        if (CheckCollisionRecs(Ent_Rec, i))
            return false;
    }
    return true;
}


bool Collision::IsCollecting(Character *Ent) {

    int count = 0;
    for (auto i : *Fruits_Vec) {
        count++;
        Fruit_area.x = i->Get_Entity_Pos().x;
        Fruit_area.y = i->Get_Entity_Pos().y;
        if (CheckCollisionRecs(Ent_Rec, Fruit_area)) {
            Ent->Collect();
            Fruits_Vec->erase(Fruits_Vec->begin() + count - 1);
            delete i;
            return true;
        }
    }
    return false;
}

bool Collision::Dmg(Character *Ent) {
    Ent_Rec = {Ent->Get_Entity_Pos().x + 7, Ent->Get_Entity_Pos().y, 32, 32};
    for (auto &i: *Traps) {
        if (CheckCollisionRecs(Ent_Rec, i)) {
            return true;
        }
    }
    return false;
}

bool Collision::Dmg(Character *Ent, Enemies *Ene) {
    Ent_Rec = {Ent->Get_Entity_Pos().x + 7, Ent->Get_Entity_Pos().y, 32, 32};
    Enemie_Rec = {Ene->Get_Entity_Pos().x, Ene->Get_Entity_Pos().y, Ene->GetProportion().x, Ene->GetProportion().y};
    return CheckCollisionRecs(Ent_Rec, Enemie_Rec);
}






