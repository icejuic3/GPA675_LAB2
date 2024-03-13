#pragma once
#include "Entity.h"

class DynamicEntity : public Entity
{
public:

	DynamicEntity(Board& board);
	~DynamicEntity();


	// Inherited via Entity
	virtual bool isValid() = 0;
	virtual bool isAlive() = 0;
	virtual void ticPrepare(real elapsedTime) = 0;
	virtual void ticExecute() = 0;
	virtual void draw(QPainter& painter) = 0;
	virtual bool isColliding(QPoint const& position) = 0;
};
