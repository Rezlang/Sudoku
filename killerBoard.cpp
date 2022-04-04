#include "KillerBoard.h"

bool KillerBoard::solve(){
    int col, row;
    //if no empty tiles solution is valid
    if (!nextEmpty(col, row)) return true;
    //iterate through all possible numbers to be placed
    for (int i=1; i<=NUM; ++i){
        if (canPlace(col, row, i)){
            //set position to valid number
            data_[col][row] = i;
            //adds value to sector's current size
            sectorSizes_[sectors_[std::pair<int,int>(col,row)]].first += i;
            //recursivly call solve
            if (solve()) return true;
            //if following solution is not valid reset position and decrease sector size
            data_[col][row] = 0;
            sectorSizes_[sectors_[std::pair<int,int>(col,row)]].first -= i;
        }
    }
    //no solutions are valid on given path
    return false;
}

bool KillerBoard::canPlace(int col, int row, int num){
    //gets index of the current sector
    int sectorIndex = sectors_[std::pair<int,int>(col,row)];
    //a number cannot repeate twice in the same column, row, and 3x3 zone
    //a sector must always contain the number specified
    //returns whether or not these conditions are satisfied
    return (!inCol(col, num) && !inRow(row, num) && !inZone(col, row, num) 
    && (sectorSizes_[sectorIndex].first + num <= sectorSizes_[sectorIndex].second));
}

void KillerBoard::loadBoard(std::ifstream &file){
    //create empty board of correct size
    std::vector<int> column(NUM, 0);
    for (int i=0; i<NUM; ++i) data_.push_back(column);
    //fill each position with number specified in file
    for (int i=0; i<NUM; ++i){
        for (int j=0; j<NUM; ++j){
            file >> data_[i][j];
        }
    }
    int x, y, sectorIndex, sectorMax;
    while (file >> y){
        file >> x;
        //if y is negative this means a new sector is starting
        if (y < 0){
            //sector index will be its position in the sectorSizes_ vector
            sectorIndex = (-1*y)-1;
            //sectorMax is the maximum value the sector can store
            sectorMax = x;
            sectorSizes_.push_back(std::pair<int,int>(0, sectorMax));
            continue;
        }
        //if y is not negative, the given point is part of the previous sector
        sectors_[std::pair<int,int>(y,x)] = sectorIndex;
    }
}