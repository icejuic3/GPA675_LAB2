#include "PauseState.h"
#include "KeyboardTransition.h"
#include "GamingState.h"
#include "GameOverState.h"
#include "KeyboardTransition.h"

PauseState::PauseState(FiniteStateMachine* fsm)
	:mFsm{fsm}
	//,mPressedKeys{}
{
}

PauseState::~PauseState()
{
}

void PauseState::draw(QPainter& painter)
{
	GamingState* gamingState = static_cast<GamingState*>(mFsm->getState(StateType::Gaming));
	gamingState->draw(painter);

	std::list<Snake*> Snakes = gamingState->getEngine().getSnakes();
	
	QRect rect(1, 1, 61, 61);
	QFont font = painter.font();

	//affichage du titre

	font.setPixelSize(9);
	painter.setFont(font);
	painter.setPen(Qt::blue);
	painter.drawText(rect, Qt::AlignHCenter | Qt::AlignTop, "Pause");

	font.setPixelSize(2);
	painter.setFont(font);
	painter.setPen(Qt::blue);

	QRect rectForPress1 = rect.adjusted(0, 0, 0, -5);
	painter.drawText(rectForPress1, Qt::AlignHCenter | Qt::AlignBottom, "Press Spacebar to return to the game");

	QRect rectForPress2 = rect.adjusted(0, 0, 0, -10);
	painter.drawText(rectForPress2, Qt::AlignHCenter | Qt::AlignBottom, "Press ESC to return to Main Menu");

	if (Snakes.size() > 1) {
		font.setPixelSize(1);
		painter.setFont(font);
		painter.setPen(Qt::darkGreen);
		QRect rectForControl1 = rect.adjusted(31, 0, 0, 0);
		painter.drawText(rectForControl1, Qt::AlignVCenter | Qt::AlignHCenter, "Control 1\n Up: I\nLeft: J\nRight: L\n Down: K");

		painter.setPen(Qt::darkRed);
		QRect rectForControl2 = rect.adjusted(0, 0, -31, 0);
		painter.drawText(rectForControl2, Qt::AlignVCenter | Qt::AlignHCenter, "Control 2\n Up: W\nLeft: A\nRight: D\n Down: S");
	}
	else {
		font.setPixelSize(1);
		painter.setFont(font);
		painter.setPen(Qt::darkGreen);
		painter.drawText(rect, Qt::AlignVCenter | Qt::AlignHCenter, "Control 1\n Up: I\nLeft: J\nRight: L\n Down: K");
	}


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
	mPressedKeys.clear();
	mTransitions.clear();
}

void PauseState::tic(qreal elapsedTime)
{

	GamingState* gamingState = static_cast<GamingState*>(mFsm->getState(StateType::Gaming));
	GamingState* homeState = static_cast<GamingState*>(mFsm->getState(StateType::Home));

	for (Qt::Key key : mPressedKeys) {

		if (key == Qt::Key_Space) {
			mTransitions.push_back(new KeyboardTransition(gamingState));
		}
		if (key == Qt::Key_Escape) {
			mTransitions.push_back(new KeyboardTransition(homeState));
		}
	}
}

void PauseState::updateKeys(const PressedKeys& pressedKeys)
{
	mPressedKeys = pressedKeys;
}
