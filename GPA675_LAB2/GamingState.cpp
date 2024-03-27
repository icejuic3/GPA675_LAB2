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
	//,mPressedKeys{}
{
}

GamingState::~GamingState()
{
}

void GamingState::draw(QPainter& painter)
{
	mSnakeEngine.draw(painter);

	std::list<Snake*> Snakes = mSnakeEngine.getSnakes();

	QRect rect(1, 1, 61, 61);
	QFont font = painter.font();

	if (Snakes.front()) {
		Snake* snake1 = Snakes.front();
		QString snake1string = "Snake 1\tScore: " + QString::number(snake1->score()) + "\tAge: " + QString::number(snake1->age()) + "\t";

		font.setPixelSize(1);
		painter.setFont(font);
		painter.setPen(Qt::darkGreen);
		painter.drawText(rect, Qt::AlignRight | Qt::AlignTop, snake1string);
	}

	if (Snakes.size() > 1) {
		Snake* snake2 = Snakes.back();
		QString snake2string = "Snake 2\tScore: " + QString::number(snake2->score()) + "\tAge: " + QString::number(snake2->age()) + "\t";

		font.setPixelSize(1);
		painter.setFont(font);
		painter.setPen(Qt::darkRed);
		painter.drawText(rect, Qt::AlignLeft | Qt::AlignTop, snake2string);
	}
}

bool GamingState::isValid()
{
	return false;
}

void GamingState::entering()
{

	if (mFsm->getGameChoice() != 0) {

		switch (mFsm->getGameChoice())					//verifie quel mode de jeu on va creer
		{
		case 1:
			mScenario = new SnakeOrigin(mSnakeEngine);
			break;
		case 2:
			mScenario = new SnakeBlockade(mSnakeEngine);
			break;

		case 3:
			mScenario = new	Snakify(mSnakeEngine);								//troisieme jeu
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
