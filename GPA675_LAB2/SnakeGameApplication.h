#pragma once
#ifndef SNAKE_GAME_APPLICATIONn_H
#define SNAKE_GAME_APPLICATIONn_H

#include <QtWidgets/QWidget>
#include <QTimer>
#include <QElapsedTimer>

#include "SnakeGameEngine.h"


class SnakeGameApplication : public QWidget
{
	Q_OBJECT
public:
	SnakeGameApplication();
	~SnakeGameApplication();
protected:
	//void keyPressEvent(QKeyEvent* event) override;
	//void keyReleaseEvent(QKeyEvent* event) override;
	void paintEvent(QPaintEvent* event) override;
private slots:

	void tic(qreal elapsedTime);

private:
	QSize const mWindowSize;
	QTimer mTimer;
	QElapsedTimer mElapsedTimer;

	/*SnakeGameEngine mSnakeGameEngine;*/
};
#endif //SNAKE_GAME_APPLICATIONn_H
