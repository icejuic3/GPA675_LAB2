#include "GameTransition.h"

GameTransition::GameTransition(State* nextState)
    :Transition(nextState)
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
