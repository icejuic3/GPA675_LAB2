#pragma once
#include "Transition.h"
#include <QtWidgets/QWidget>
#include <QKeyEvent>

class KeyboardTransition: public Transition
{
public:
	KeyboardTransition(State* sourceState, State* nextState, Qt::Key key);
	~KeyboardTransition();

	bool isTransiting() override;

protected:
	void keyPressEvent(QKeyEvent* event);
	void keyReleaseEvent(QKeyEvent* event);

private:

	Qt::Key mkey; // La touche qui déclenchera la transition
	bool mTransiting;
};
