#include "HomeState.h"
#include "KeyboardTransition.h"

#include "HomeState.h"
#include "GamingState.h"
#include "GameOverState.h"
#include "PauseState.h"

HomeState::HomeState(FiniteStateMachine* fsm)
	://mGamingState()
	mFsm{fsm}
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
	GamingState* gamingState = static_cast<GamingState*>(mFsm->getState(StateType::Gaming));

	mTransitions.push_back(new KeyboardTransition(gamingState, Qt::Key_Enter));
}
