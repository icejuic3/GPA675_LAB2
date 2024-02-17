#include "StaticEntity.h"

bool StaticEntity::isValid()
{
    return false;
}

bool StaticEntity::isAlive()
{
    return false;
}

void StaticEntity::ticPrepare(real elapsedTime)
{
}

void StaticEntity::ticExecute()
{
}

void StaticEntity::draw(QPainter& painter)
{
}

bool StaticEntity::isColliding(QPoint const& position)
{
    return false;
}
