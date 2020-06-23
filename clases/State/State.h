//
// Created by martin on 10/6/20.
//

#ifndef RAYLIBTEMPLATE_STATE_H
#define RAYLIBTEMPLATE_STATE_H


class State {
private:
public:
    virtual void On() = 0;

    virtual int Off() = 0;
};


#endif //RAYLIBTEMPLATE_STATE_H
