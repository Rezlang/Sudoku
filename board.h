#define __Board
#ifdef __Board

#include <vector>
#include <iostream>
#include <fstream>

extern const int NUM;
class Board{
    public:
    //Constructor
    Board(std::ifstream &file){loadBoard(file);};
    //Constructor Helper
    void loadBoard(std::ifstream &file);

    //returns true if given num can be placed at position (col, row)
    bool canPlace(int col, int row, int num);
    //canPlace Helpers
    bool inCol(int col, int num);
    bool inRow(int row, int num);
    bool inZone(int col, int row, int num);

    //finds next tile on board that is empty (0 represents empty). 
    //if all full returns true
    bool nextEmpty(int &col, int &row);

    //Representation
    void printBoard(std::ofstream &file);

    //Solver
    bool solve();

    protected:
    //2d int vector that holds grid data
    std::vector<std::vector<int> > data_;
};

#endif