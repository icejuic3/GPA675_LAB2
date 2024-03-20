#include "HomeState.h"
#include "KeyboardTransition.h"

HomeState::HomeState()
{
}

HomeState::~HomeState()
{
}

void HomeState::draw(QPainter& painter)
{
}

bool HomeState::isValid()
{
	return false;
}

void HomeState::entering()
{
}

void HomeState::exiting()
{
}

void HomeState::tic(qreal elapsedTime)
{

	mTransitions.push_back(new KeyboardTransition(this, this, Qt::Key_Enter));

}
