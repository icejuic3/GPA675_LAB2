#include "StaticEntity.h"

StaticEntity::StaticEntity(Board& board)
    : Entity(board)
    , mColor{Qt::blue}
    , mPosition{ 32,32 }
    , mRadius{ 1 }
{
    
}

StaticEntity::~StaticEntity()
{
    mBoard.setValue(mPosition.x(), mPosition.y(), nullptr);
}

bool StaticEntity::isValid()
{
    return false;
}

bool StaticEntity::isAlive()
{
    return mAlive;
}

void StaticEntity::ticPrepare(real elapsedTime)
{
    if (isColliding(mPosition)) {
        mAlive = false;
        return;
    }

}

void StaticEntity::ticExecute()
{
    mAge += 1;
}

void StaticEntity::draw(QPainter& painter)
{
    painter.setPen(Qt::NoPen);
    painter.setPen(mColor);
    painter.drawPoint(mPosition);
}

bool StaticEntity::isColliding(QPoint const& position)
{
    return mBoard.value(position.x(),position.y()) != this;
}

QPoint StaticEntity::position() const
{
    return mPosition;
}

QColor StaticEntity::color() const
{
    return mColor;
}

void StaticEntity::setPosition(QPoint position)
{
    mPosition = position;
    mBoard.setValue(position.x(), position.y(), this);
}

void StaticEntity::setColor(QColor color)
{
    mColor = color;
}