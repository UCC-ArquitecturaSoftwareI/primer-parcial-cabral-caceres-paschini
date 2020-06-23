//
// Created by martin on 20/5/20.
//


#include "Animation_Creator.h"


/**This Function is the base for the flyweight pattern .It receives a pointer of a vector of pointers of entities and
 * decides if it should create an image for it or use one that was already in use
 * @param Vector_file Has the entities
 * **/
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