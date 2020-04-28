//
// Created by Catalina on 28/04/2020.
//

#ifndef PRIMER_PARCIAL_CABRAL_CACERES_PASCHINI_PADRE_H
#define PRIMER_PARCIAL_CABRAL_CACERES_PASCHINI_PADRE_H

#include <raylib.h>
#include <string>
#include <utility>
#include <vector>

class padre{
protected:
    std::string FilePath;
    Vector2 Pos;
    std:: vector<int> MaxColumn;
    Rectangle Frame;
public:

    virtual void Move_x (float d) = 0; // clase virtual abstracta para ser implementada en cada personaje

    virtual Vector2 &GetPos () = 0; // clase virtual abstracta para ser implementada en cada personaje

    const std::string &getFilePath() const {
        return FilePath;
    }

    const std::vector<int> &getMaxColumn() const {
        return MaxColumn;
    }
};

#endif //PRIMER_PARCIAL_CABRAL_CACERES_PASCHINI_PADRE_H
