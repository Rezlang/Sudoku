#define __KBoard
#ifdef __KBoard

#include <vector>
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <map>
#include <memory>

extern const int NUM;
class KillerBoard{
    public:
    //constructor
    KillerBoard(std::ifstream &file){loadBoard(file);};

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
    bool solve(int* sectorSize);

    protected:
    //stores the grid in NUM * NUM 2d vector
    std::vector<std::vector<int> > data_;

    //key pair stores y coordinate and x coordinate
    //value pair stores index of sector in sectorSizes
    std::map<std::pair<int,int>, int > sectors;

    //stors pair of current sector size and max sector size
    std::vector<std::pair<int,int> > sectorSizes;
};

#endif