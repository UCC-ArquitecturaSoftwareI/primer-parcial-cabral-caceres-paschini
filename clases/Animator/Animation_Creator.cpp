//
// Created by martin on 20/5/20.
//

#include "Animation_Creator.h"

void Animation_Creator::Create(std::vector<Entity *> *Vector_file) {
    Image_Holder *Img;
    std::string temp;
    temp = Vector_file->front()->GetFilePathText();
    Img = new Image_Holder(Vector_file->front()->GetMaxCol(),Vector_file->front()->GetFilePathText());

    for (auto i: *Vector_file) {
        if (i->GetFilePathText() == temp) {
            Img = new Image_Holder(i->GetMaxCol(), i->GetFilePathText());
            temp =i->GetFilePathText();
        }
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

void Animation_Creator::Create(std::vector<Fruits *> *Vector_file) {
    Image_Holder *Img;
    std::string temp;
    temp = Vector_file->front()->GetFilePathText();
    Img = new Image_Holder(Vector_file->front()->GetMaxCol(),Vector_file->front()->GetFilePathText());

    for (auto i: *Vector_file) {
        if (i->GetFilePathText() == temp) {
            Img = new Image_Holder(i->GetMaxCol(), i->GetFilePathText());
            temp =i->GetFilePathText();
        }
        Animation *Ani;
        Ani = new Animation(Img);
        i->Assign_Animator(Ani);

    }
}
