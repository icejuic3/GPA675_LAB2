#include "DynamicEntity.h"

bool DynamicEntity::isValid()
{
	return false;
}

bool DynamicEntity::isAlive()
{
	return false;
}

void DynamicEntity::ticPrepare(real elapsedTime)
{
}

void DynamicEntity::ticExecute()
{
}

void DynamicEntity::draw(QPainter& painter)
{
}

bool DynamicEntity::isColliding(QPoint const& position)
{
	return false;
}
