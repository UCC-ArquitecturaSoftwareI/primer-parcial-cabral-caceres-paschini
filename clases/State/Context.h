//
// Created by martin on 16/6/20.
//

#ifndef RAYLIBTEMPLATE_CONTEXT_H
#define RAYLIBTEMPLATE_CONTEXT_H

#include "State.h"

class Context {
private:
    State *Current_State;
public:
    Context() = default;

    void SetCurrentState(State *S) {
        Current_State = S;
    }

    void Start_State();

    int Stop_State();

};


#endif //RAYLIBTEMPLATE_CONTEXT_H
