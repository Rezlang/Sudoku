#ifndef __RegularBoard
#define __RegularBoard

#include "board.h"
#include <vector>
#include <iostream>
#include <fstream>

extern const int NUM;
class RegularBoard : public Board{
    public:
    //Constructor
    RegularBoard(std::ifstream &file){loadBoard(file);};
    //Constructor helper
    void loadBoard(std::ifstream &file);

    //Returns whether num can be placed at position (col, row)
    bool canPlace(int col, int row, int num);

    //Solver
    bool solve();

};

#endif