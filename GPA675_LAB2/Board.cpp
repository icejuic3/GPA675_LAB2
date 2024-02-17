#include "Board.h"

Board::Board()
    :mHeight{ 0 }
    ,mWidth{ 0 }
    ,mSize{ 0 }
    ,mBoard{ nullptr }
{
}

Board::Board(size_t height, size_t width, Cellstate initValue)
    :mHeight{ height }
    ,mWidth{ width }
    ,mSize{ height * width }
    ,mBoard{ new Cellstate[mSize] }
{

    //validation des valeurs de la grille
    if (width >= 4 && height >= 3 && width % 2 == 0) {

        for (DataState cur{ mBoard }; cur < mBoard + mSize; ++cur) {

            *cur = initValue;
        }
    }
    else {
        throw std::invalid_argument("Les dimensions de la grille ne sont pas valide");      //Confirmer ce qu'on doit faire si nous recevons la mauvaise taille de tableau
    }
}

Board& Board::operator=(Board const&)
{
    return *this;
}

Board::~Board()
{
    delete[]mBoard;
    mBoard = nullptr;
}

size_t Board::getWidth() const
{
    return mWidth;
}

size_t Board::getHeight() const
{
    return mHeight;
}

size_t Board::getSize() const
{
    return mSize;
}

void Board::setState(size_t row, size_t column, Cellstate value)
{
    mBoard[row * mWidth + column] = value;
}

DataState const& Board::data() const
{
    return mBoard;
}

DataState& Board::data()
{
    return mBoard;
}

Cellstate Board::value(size_t row, size_t column) const
{
    return mBoard[row * mWidth + column];
}