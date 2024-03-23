#include "GamingState.h"
#include "KeyboardTransition.h"
#include "GameTransition.h"

#include "HomeState.h"
#include "GameOverState.h"
#include "PauseState.h"

GamingState::GamingState(FiniteStateMachine* fsm)
	:mFsm{ fsm }
	,mScenario{}
{
}

GamingState::~GamingState()
{
}

void GamingState::draw(QPainter& painter)
{
	mSnakeEngine.draw(painter);
}

bool GamingState::isValid()
{
	return false;
}

void GamingState::entering()
{
	mSnakeEngine.startGameEngine();
}

void GamingState::exiting()
{
	mSnakeEngine.endGameEngine();
}

void GamingState::tic(qreal elapsedTime)
{
	mSnakeEngine.tic(elapsedTime);
	

	PauseState* pauseState = static_cast<PauseState*>(mFsm->getState(StateType::Pause));
	GameOverState* gameOver = static_cast<GameOverState*>(mFsm->getState(StateType::GameOver));

	if (mScenario->isGameOver()) {

		mTransitions.push_back(new GameTransition(gameOver));
	}
}

void GamingState::updateKeys(const PressedKeys& pressedKeys)
{
	mSnakeEngine.snakeDirection(pressedKeys);
	mPressedKeys = pressedKeys;
}
