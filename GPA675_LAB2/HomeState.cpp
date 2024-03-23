#include "HomeState.h"
#include "GamingState.h"
#include "GameOverState.h"
#include "PauseState.h"
#include "KeyboardTransition.h"
#include <Qrect>


HomeState::HomeState(FiniteStateMachine* fsm)
	:mFsm{fsm}
	,mPressedKeys{}
{
}

HomeState::~HomeState()
{
}

void HomeState::draw(QPainter& painter)
{
	QRect rect(0, 0, 64, 64);
	QFont font = painter.font();

	//affichage du titre
	painter.fillRect(rect, Qt::darkGreen);

	font.setPixelSize(16);
	painter.setFont(font);
	painter.setPen(Qt::green);
	painter.drawText(rect, Qt::AlignHCenter | Qt::AlignTop, "SNAKE!");

	//section pour l'affichage du texte
	font.setPixelSize(4);
	painter.setFont(font);
	painter.setPen(Qt::darkRed);

	QRect rectForPress1 = rect.adjusted(0, 24, 0, -32);
	painter.drawText(rectForPress1, Qt::AlignVCenter , "Press 1: SnakeOrigin");

	QRect rectForPress2 = rect.adjusted(0, 30, 0, -26);
	painter.drawText(rectForPress2, Qt::AlignVCenter, "Press 2: Snakify");
	
	QRect rectForPress3 = rect.adjusted(0, 36, 0, -20);
	painter.drawText(rectForPress3, Qt::AlignVCenter , "Press 3: SnakeBlockade");

	QRect rectForPress4 = rect.adjusted(0, 42, 0, -14);
	painter.drawText(rectForPress4, Qt::AlignVCenter, "Press Spacebar to pause the game");

	QRect rectForPress5 = rect.adjusted(0, 48, 0, -8);
	painter.drawText(rectForPress5, Qt::AlignVCenter, "Press ESC to Quit");
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


	for (Qt::Key key : mPressedKeys) {
		if (key == Qt::Key_1 ) {
			mTransitions.push_back(new KeyboardTransition(gamingState)); // La touche 1 a été pressée
		}
		else if (key == Qt::Key_2) {
			mTransitions.push_back(new KeyboardTransition(gamingState)); // La touche 2 a été pressée, faire quelque chose
		}
		else if (key == Qt::Key_3) {
			mTransitions.push_back(new KeyboardTransition(gamingState)); // La touche 3 a été pressée, faire quelque chose
		}
	}
}

void HomeState::updateKeys(const PressedKeys& pressedKeys)
{
	mPressedKeys = pressedKeys;
}
