#include "GameOverState.h"
#include "KeyboardTransition.h"
#include "HomeState.h"
#include "GamingState.h"

GameOverState::GameOverState(FiniteStateMachine* fsm)
	:mFsm{ fsm }
	//,mPressedKeys{}
{
}

GameOverState::~GameOverState()
{
}

void GameOverState::draw(QPainter& painter)
{
	QRect rect(0, 0, 64, 64);
	QFont font = painter.font();

	//affichage du titre

	font.setPixelSize(12);
	painter.setFont(font);
	painter.setPen(Qt::red);
	painter.drawText(rect, Qt::AlignHCenter | Qt::AlignTop, "Game Over!");

	font.setPixelSize(4);
	painter.setFont(font);
	painter.setPen(Qt::black);

	QRect rectForPress4 = rect.adjusted(1, 42, 0, -14);
	painter.drawText(rectForPress4, Qt::AlignVCenter, "Press Spacebar to return to menu");

	QRect rectForPress5 = rect.adjusted(1, 48, 0, -8);
	painter.drawText(rectForPress5, Qt::AlignVCenter, "Press ESC to Quit");

	GamingState* gamingState = static_cast<GamingState*>(mFsm->getState(StateType::Gaming));
	gamingState->draw(painter);

}

bool GameOverState::isValid()
{
	return false;
}

void GameOverState::entering()
{

}

void GameOverState::exiting()
{
	mPressedKeys.clear();
	mTransitions.clear();
}

void GameOverState::tic(qreal elapsedTime)
{
	mSnakeEngine.tic(elapsedTime);

	GamingState* homeState = static_cast<GamingState*>(mFsm->getState(StateType::Home));

	for (Qt::Key key : mPressedKeys) {

		if (key == Qt::Key_Escape) {
			QCoreApplication::quit();		//met fin a l'application
		}
		if (key == Qt::Key_Space) {
			mTransitions.push_back(new KeyboardTransition(homeState));
		}
	}

}

void GameOverState::updateKeys(const PressedKeys& pressedKeys)
{
	mSnakeEngine.snakeDirection(pressedKeys);
	mPressedKeys = pressedKeys;
}
