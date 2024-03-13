#include "Board.h"
#include "Entity.h"

Board::Board()
    :mHeight{ 0 }
    , mWidth{ 0 }
    , mSize{ 0 }
    , mBoard{nullptr}
{
}

Board::Board(size_t height, size_t width)
    :mHeight{ height }
    , mWidth{ width }
    , mSize{ height * width }
    , mBoard{ new CellType[mSize] }									//initialisation du pointeur de ligne
{  
    //validation des valeurs de la grille
    if (width < 4 || height < 3 || width % 2 != 0) {

        //retourne message d'erreur **peut-etre remplacer la mauvaise valeur?
        throw std::invalid_argument("Les dimensions de la grille ne sont pas valide");
    }

    for (DataType cur{ mBoard }; cur < mBoard + mSize; ++cur) {
        *cur = nullptr;											//l'état est sauvegarder a l'endroit où pointe le pointeur
    }
}

Board& Board::operator=(Board const&)
{
    return *this;
}

Board::~Board()
{
    //delete[]mBoard;
    //mBoard = nullptr;
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