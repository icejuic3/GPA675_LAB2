#include "GameOverState.h"
#include "KeyboardTransition.h"

GameOverState::GameOverState(FiniteStateMachine* fsm)
	:mFsm{ fsm }
	,mPressedKeys{}
{
}

GameOverState::~GameOverState()
{
}

void GameOverState::draw(QPainter& painter)
{
	mSnakeEngine.draw(painter);

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
}

void GameOverState::tic(qreal elapsedTime)
{
	//mSnakeEngine.tic(elapsedTime);








}

void GameOverState::updateKeys(const PressedKeys& pressedKeys)
{
}
