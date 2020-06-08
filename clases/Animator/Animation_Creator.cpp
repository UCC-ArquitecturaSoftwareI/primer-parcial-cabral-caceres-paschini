//
// Created by martin on 20/5/20.
//

#include "Animation_Creator.h"

void Animation_Creator::Create(std::vector<Entity *> *Vector_file) {
    for (auto i: *Vector_file) {
        {
            auto result = Map.find(i->GetFilePathText());
            if(result != Map.end()){
                Animation *Ani;
                Ani = new Animation(result->second);
                i->Assign_Animator(Ani);
            } else{
                Image_Holder *Img;
                Img = new Image_Holder(i->GetMaxCol(),i->GetFilePathText(),i->GetProportion());
                Map.insert_or_assign(i->GetFilePathText(),Img);
                Animation *Ani;
                Ani = new Animation(Img);
                i->Assign_Animator(Ani);
            }
        }

    }
}

void Animation_Creator::Create(Entity *Ent) {
    Image_Holder *Img;
    Img = new Image_Holder(Ent->GetMaxCol(), Ent->GetFilePathText(), Ent->GetProportion());

    Animation *Ani;
    Ani = new Animation(Img);
    Ent->Assign_Animator(Ani);
}

void Animation_Creator::Create(std::vector<Fruits *> *Vector_file) {
    Image_Holder *Img;
    std::string temp;
    temp = Vector_file->front()->GetFilePathText();
    Img = new Image_Holder(Vector_file->front()->GetMaxCol(), Vector_file->front()->GetFilePathText(),
                           Vector_file->front()->GetProportion());

    for (auto i: *Vector_file) {
        Animation *Ani;
        Ani = new Animation(Img);
        i->Assign_Animator(Ani);

    }
}
