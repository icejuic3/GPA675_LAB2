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

class QPainter;

class SnakeGameEngine
{
private:
	QSize mSize;
	qreal mSpeed;
	qreal mTotalElapsedTime;
	std::list<Entity*> mEntities;
	Board mBoard;

public:
	//
	SnakeGameEngine(QSize const& size);
	~SnakeGameEngine();

	void tic(qreal elapsedTime);
	void draw(QPainter& painter);
	void clearAllEntity();
	void addEntity(Entity* entity);

	// random position
	QPoint randomPosition();
	void randomPellet();

	void startGameEngine();

};

#endif