#include "Context.h"

void Context::Start_State() {
    return Current_State->On();
}

int Context::Stop_State() {
    return Current_State->Off();
}
