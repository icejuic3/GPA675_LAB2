#include "PauseState.h"
#include "KeyboardTransition.h"

#include "GamingState.h"
#include "GameOverState.h"
#include "KeyboardTransition.h"

PauseState::PauseState(FiniteStateMachine* fsm)
	:mFsm{ fsm }
	,mPressedKeys{}
{
}

PauseState::~PauseState()
{
}

void PauseState::draw(QPainter& painter)
{
	mSnakeEngine.draw(painter);
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
	mSnakeEngine.tic(elapsedTime);

	GamingState* gamingState = static_cast<GamingState*>(mFsm->getState(StateType::Gaming));

	for (Qt::Key key : mPressedKeys) {

		if (key == Qt::Key_Space) {
			mTransitions.push_back(new KeyboardTransition(gamingState));
		}
	}
}

void PauseState::updateKeys(const PressedKeys& pressedKeys)
{
	mPressedKeys = pressedKeys;
}
