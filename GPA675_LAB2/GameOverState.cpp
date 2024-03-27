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

	std::list<Snake*> Snakes = gamingState->getEngine().getSnakes();

	font.setPixelSize(5);
	painter.setFont(font);

	if (Snakes.size() > 1) {
		int score1 = Snakes.front()->score();
		int score2 = Snakes.back()->score();

		QString winner = "";
		QString score = "";
		if (score1 > score2) {
			painter.setPen(Qt::darkGreen);
			winner = "Player 1 WINS";
			score = QString::number(score1);
		}
		else if (score2 > score1) {
			painter.setPen(Qt::darkRed);
			winner = "Player 2 WINS";
			score = QString::number(score2);
		}
		else {
			painter.setPen(Qt::blue);
			winner = "DRAW";
			score = QString::number(score2);
		}
		
		painter.drawText(rect, Qt::AlignVCenter | Qt::AlignHCenter, winner);

		font.setPixelSize(2);
		painter.setFont(font);
		QRect rectForScore = rect.adjusted(0, 10, 0, 0);
		painter.drawText(rectForScore, Qt::AlignVCenter | Qt::AlignHCenter, "With Score: " + score);
	}
	else {
		QString score1 = QString::number(Snakes.front()->score());
		font.setPixelSize(3);
		painter.setFont(font);
		painter.setPen(Qt::darkGreen);
		painter.drawText(rect, Qt::AlignVCenter | Qt::AlignHCenter, "Final Score: " + score1);
	}
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
	GamingState* gamingState = static_cast<GamingState*>(mFsm->getState(StateType::Gaming));

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
