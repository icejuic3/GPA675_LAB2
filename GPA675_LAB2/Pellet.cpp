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
