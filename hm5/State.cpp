//
// Created by Stephen Clyde on 3/4/17.
//

#include "State.h"

// Done: implement State class functionality

State::State(const std::string *data) : Region(StateType, data){
    validate();
}