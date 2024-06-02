#include "State.h"

// Initialize the states
IState * IState::mainState     = new MainState;
IState * IState::optionalState = new OptionalState;
IState * IState::currentState  = IState::mainState;


int main () {
    while(true){
        IState::currentState->enter();
        IState::currentState->update();
    }
    return 0;
}