#include "GamingState.h"
#include "KeyboardTransition.h"
#include "GameTransition.h"

GamingState::GamingState()
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

	if (mScenario->isGameOver()) {
		mTransitions.push_back(new GameTransition(this, mGameOver));
	}
}

void GamingState::initialiseTransition()
{
	//mTransitions.push_back(new KeyboardTransition(this, this, Qt::Key_Enter));

}