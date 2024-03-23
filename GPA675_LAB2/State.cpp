#include "State.h"


State::State()
	:mTransitions{}
{
}

State* State::isTransiting() {

	for (auto& transition : mTransitions) {
		
		if (transition->isTransiting()) {

			return transition->state();
		}
	}

	return nullptr;
}