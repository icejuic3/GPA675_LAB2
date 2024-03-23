#pragma once
#include "Transition.h"
#include <QtWidgets/QWidget>
#include <QKeyEvent>

class KeyboardTransition: public Transition
{
public:
	KeyboardTransition(State* nextState);
	~KeyboardTransition();

	bool isTransiting() override;

protected:
	//void keyPressEvent(QKeyEvent* event);
	//void keyReleaseEvent(QKeyEvent* event);

private:

	State* mNextState;
};
