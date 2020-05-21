//
// Created by martin on 20/5/20.
//

#include "Animation_Creator.h"

void Animation_Creator::Create(std::vector<Entity *> list_file) {
    Image_Holder *Img;
    Img = new Image_Holder(list_file[0]->GetMaxCol(), list_file[0]->GetFilePathText());

    for (auto i: list_file) {
        Animation *Ani;
        Ani = new Animation(Img);
        i->Assign_Animator(Ani);
    }
}

void Animation_Creator::Create(Entity *Ent) {
    Image_Holder *Img;
    Img = new Image_Holder(Ent->GetMaxCol(), Ent->GetFilePathText());

    Animation *Ani;
    Ani = new Animation(Img);
    Ent->Assign_Animator(Ani);
}