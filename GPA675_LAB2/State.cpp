#include "State.h"
#include "KeyboardTransition.h"


State::State()
	:mTransitions{}
{
}

Transition* State::isTransiting() {

	for (auto& transition : mTransitions) {
		
		if (transition->isTransiting()) {
			return transition;
		}
	}

	return nullptr;
}