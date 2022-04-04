#ifndef __Board
#define __Board

#include <vector>
#include <iostream>
#include <fstream>

extern const int NUM;
class Board{
    protected:
    //Constructor helper
    virtual void loadBoard(std::ifstream &file) = 0;
    //Main puzzle solver
    virtual bool solve() = 0;
    //Returns whether num can be placed at position (col, row)
    virtual bool canPlace(int col, int row, int num) = 0;

    //Helpers for canPlace
    bool inCol(int col, int num);
    bool inRow(int row, int num);
    bool inZone(int col, int row, int num);

    //Finds next tile on board that is empty (0 represents empty). 
    //if all full returns true
    bool nextEmpty(int &col, int &row);

    //Stores grid data in 2d int vector
    std::vector<std::vector<int> > data_;

    public:
    //Representation
    void printBoard(std::ofstream &file);
};

#endif