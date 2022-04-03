#define __Board
#ifdef __Board

#include <vector>
#include <iostream>
#include <fstream>

extern const int NUM;
class Board{
    public:
    //constructor
    Board(std::ifstream &file){loadBoard(file);};

    void loadBoard(std::ifstream &file);

    //Helpers
    bool inCol(int col, int num);
    bool inRow(int row, int num);
    bool inZone(int col, int row, int num);

    bool canPlace(int col, int row, int num);

    bool nextEmpty(int &col, int &row);

    //Representation
    void printBoard(std::ofstream &file);

    //Solver
    bool solve();

    protected:
    std::vector<std::vector<int> > data_;
};

#endif