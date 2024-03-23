#include "PauseState.h"
#include "KeyboardTransition.h"

PauseState::PauseState()
{
}

PauseState::~PauseState()
{
}

void PauseState::draw(QPainter& painter)
{
}

bool PauseState::isValid()
{
	return false;
}

void PauseState::entering()
{
}

void PauseState::exiting()
{
}

void PauseState::tic(qreal elapsedTime)
{
}

void PauseState::updateKeys(const PressedKeys& pressedKeys)
{
}
