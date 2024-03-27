#include "GamingState.h"
#include "KeyboardTransition.h"
#include "GameTransition.h"


#include "SnakeOrigin.h"
#include "SnakeBlockade.h"
#include "Snakify.h"


#include "HomeState.h"
#include "GameOverState.h"
#include "PauseState.h"

GamingState::GamingState(FiniteStateMachine* fsm)
	:mFsm{ fsm }
	,mScenario{nullptr}
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

	if (mFsm->getGameChoice() != 0) {

		switch (mFsm->getGameChoice())						//verifie quel mode de jeu on va creer
		{
		case 1:
			mScenario = new SnakeOrigin(mSnakeEngine);
			break;
		case 2:
			mScenario = new SnakeBlockade(mSnakeEngine);
			break;

		case 3:
			mScenario = new	Snakify(mSnakeEngine);			//troisieme jeu
			break;

		}
		mSnakeEngine.setGameMode(mFsm->getGameChoice());	//envoi le mode de jeu au Game Engine
		mScenario->startGame();								//initialisation de la partie
	}
}

void GamingState::exiting()
{
	mFsm->setGameChoice(0);
	mPressedKeys.clear();
	mTransitions.clear();
}

void GamingState::tic(qreal elapsedTime)
{
	mSnakeEngine.tic(elapsedTime);
	
	PauseState* pauseState = static_cast<PauseState*>(mFsm->getState(StateType::Pause));
	GameOverState* gameOver = static_cast<GameOverState*>(mFsm->getState(StateType::GameOver));

	if (mScenario->isGameOver()) {
		mTransitions.push_back(new GameTransition(gameOver));
	}

	for (Qt::Key key : mPressedKeys) {

		if (key == Qt::Key_Escape) {
			QCoreApplication::quit();		//met fin a l'application
		}
		else if (key == Qt::Key_Space) {
			mTransitions.push_back(new KeyboardTransition(pauseState));		//met pause a la partie
		}
	}
}

void GamingState::updateKeys(const PressedKeys& pressedKeys)
{
	mSnakeEngine.snakeDirection(pressedKeys);
	mPressedKeys = pressedKeys;
}
