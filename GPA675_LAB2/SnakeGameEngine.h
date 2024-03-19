#pragma once
#ifndef SNAKE_GAME_ENGINE
#define SNAKE_GAME_ENGINE


#include <list>
#include <QtWidgets/QWidget>
#include <QTimer>
#include <QElapsedTimer>
#include <QSize>

#include "Entity.h"
#include "Snake.h"
#include "Pellet.h"
#include "PressedKeys.h"
#include "control.h"
#include "Obstacle.h"

class QPainter;

class SnakeGameEngine
{
private:
	std::list<Entity*> mEntities;
	qreal mSpeed;
	qreal mTotalElapsedTime;
	Board mBoard;
	PressedKeys mPressedKeys;
	QSize mSize;				//deplacer dans gamingState

public:
	//
	SnakeGameEngine(QSize const& size); 
	//SnakeGameEngine();
	~SnakeGameEngine();

	void tic(qreal elapsedTime);
	void draw(QPainter& painter);
	void clearAllEntity();
	void addEntity(Entity* entity);

	// random position
	QPoint randomPosition();
	void randomPellet();
	void arene();
	void addSnake();
	void startGameEngine();
	void snakeDirection(const PressedKeys& pressedKeys);

};

#endif