#include "GameTransition.h"

GameTransition::GameTransition(State* sourceState, State* nextState)
    :Transition(sourceState, nextState)
    ,mTransiting{true}
{
}

GameTransition::~GameTransition()
{
}

bool GameTransition::isTransiting()
{
    return mTransiting;
}
