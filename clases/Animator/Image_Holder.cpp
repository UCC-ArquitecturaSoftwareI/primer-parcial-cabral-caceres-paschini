//
// Created by martin on 20/5/20.
//

#include "Image_Holder.h"

Image_Holder::Image_Holder(std::vector<int> max_Column, std::string file) {
    for(auto i : max_Column){
        maxColumn.push_back(i);
    }
    Picture = LoadTexture(file.c_str());
}

const Texture2D &Image_Holder::getPicture() const {
    return Picture;
}

const std::vector<int> &Image_Holder::getMaxColumn() const {
    return maxColumn;
}
