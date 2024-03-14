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

}

void StaticEntity::ticExecute()
{
    mAge += 1;
}

void StaticEntity::draw(QPainter& painter)
{
    painter.setPen(Qt::NoPen);
    painter.setBrush(mColor);
    painter.drawEllipse(QRectF(mPosition, QSize(mRadius, mRadius)));
}

bool StaticEntity::isColliding(QPoint const& position)
{

    return mPosition == position;
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
}

void StaticEntity::setColor(QColor color)
{
    mColor = color;
}