#pragma once
#ifndef SNAKE_GAME_ENGINE
#define SNAKE_GAME_ENGINE


#include <list>
#include <QtWidgets/QWidget>
#include <QTimer>
#include <QElapsedTimer>

#include "Entity.h"

class QPainter;

		
class SnakeGameEngine : public Entity
{
private:
	std::list<Entity*> mEntity;
public:
	SnakeGameEngine(Entity& entity);
	~SnakeGameEngine() ;
	void tic(qreal elapsedTime);
	void draw(QPainter& painter);
	void clearAllEntity();	
	void addEntity(Entity* entity);
};

#endif
