#include "Board.h"
#include <vector>


int main(int argc, char* argv[])
{
    /*********************Section de Test****************************/
  
    size_t row=3;
    size_t column=4;
    Board board1{row,column};
    std::vector<State> states;

    board1.setState(0, 3, State::occupied);
    int compteur{};

    for (DataState x{ board1.data() }; x < board1.data() + board1.getSize(); ++x) { 

        states.push_back(*x);
        std::cout << x;
    }
    

    return 0;
    /*************************************************/






    /*QApplication application(argc, argv);
    GPA675Lab2StartingProject window;

    window.show();
    return application.exec();*/
}
