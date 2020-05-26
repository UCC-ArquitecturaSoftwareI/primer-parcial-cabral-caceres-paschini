//
// Created by Martin on 26/04/2020.
//

#include "Animation.h"


Animation::Animation(Image_Holder *img) {
    currentColumn = 0;
    currentRow = 0;
    image = img;
    frameRec = {0.0f, 0.0f, image->getProportion().x, image->getProportion().y};

}


void Animation::Animate(Vector2 pos) {

    frameRec = {static_cast<float>(currentColumn * image->getProportion().x), static_cast<float>(currentRow * image->getProportion().y), image->getProportion().x, image->getProportion().y};
    DrawTextureRec(image->getPicture(), frameRec, pos, WHITE);
    currentColumn = ++currentColumn % image->getMaxColumn()[currentRow];
}

void Animation::setCurrentRow(int currentRow) {
    Animation::currentRow = currentRow;
}
