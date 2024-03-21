#include "KeyboardTransition.h"

KeyboardTransition::KeyboardTransition(State* nextState, Qt::Key key)
	:Transition(nextState)
	,mkey{key}
	,mTransiting{false}
{
}

KeyboardTransition::~KeyboardTransition()
{
}

bool KeyboardTransition::isTransiting()
{
	return mTransiting;
}

void KeyboardTransition::keyPressEvent(QKeyEvent* event)
{
	if (event->key() == mkey) {
		mTransiting = true;
	}
}

void KeyboardTransition::keyReleaseEvent(QKeyEvent* event)
{
	if (event->key() == mkey) {
		mTransiting = false;
	}
}