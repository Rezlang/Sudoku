#include "regularBoard.h"



bool RegularBoard::solve(){
    int col, row;
    //if no empty tiles solution is valid
    if (!nextEmpty(col, row)) return true;
    //iterate through all possible numbers to be placed
    for (int i=1; i<=NUM; ++i){
        if (canPlace(col, row, i)){
            //set position to valid number
            data_[col][row] = i;
            //recursivly call solve
            if (solve()) return true;
            //if following solution is not valid reset position
            data_[col][row] = 0;
        }
    }
    //no solutions are valid on given path
    return false;
}

bool RegularBoard::canPlace(int col, int row, int num){
    //a number cannot repeate twice in the same column, row, and 3x3 zone
    //returns whether or not these conditions are satisfied
    return (!inCol(col, num) && !inRow(row, num) && !inZone(col, row, num));
}

void RegularBoard::loadBoard(std::ifstream &file){
    std::vector<int> column;
    int x;
    //read in integers until none left
    while (file >> x){
        //add integer to current column
        column.push_back(x);
        //if column is full
        if (column.size() == NUM){
            //push back column to board data and clear column
            data_.push_back(column);
            column.clear();
        }
    }
}