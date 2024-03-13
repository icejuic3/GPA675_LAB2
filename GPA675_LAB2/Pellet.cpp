#include "Pellet.h"

Pellet::Pellet(Board& board)
    :StaticEntity(board)
    ,mScore{0}
{
}

Pellet::~Pellet()
{
}

int Pellet::score()
{
    return mScore;
}

void Pellet::setScore(int score)
{
    mScore = score;
}


//void GrowingPellet::applyEffectOnSnake(Snake& snake)
//{
//    //snake.grow(1);
//}
//
//void AcceleratingPellet::applyEffectOnSnake(Snake& snake)
//{
//    //snake.increaseSpeed(1);
//}