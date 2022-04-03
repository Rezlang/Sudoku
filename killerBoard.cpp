#include "KillerBoard.h"

bool KillerBoard::inCol(int col, int num){
    for (int r=0; r<NUM; ++r){
        if (data_[col][r] == num) return true;
    }
    return false;
}

bool KillerBoard::inRow(int row, int num){
    for (int c=0; c<NUM; ++c){
        if (data_[c][row] == num) return true;
    }
    return false;
}

bool KillerBoard::inZone(int col, int row, int num){
    for (int c = col/3*3; c < (col/3*3)+3; ++c){
        for (int r = row/3*3; r < (row/3*3) + 3; ++r){
            if (data_[c][r] == num) return true;
        }
    }
    return false;
}

bool KillerBoard::nextEmpty(int &col, int &row){
    for (col = 0; col<NUM; ++col){
        for (row = 0; row<NUM; ++row){
            if (data_[col][row] == 0) return true;
        }
    }
    return false;
}

bool KillerBoard::solve(){
    int col, row;
    if (!nextEmpty(col, row)) return true;
    for (int i=1; i<=NUM; ++i){
        if (canPlace(col, row, i)){
            data_[col][row] = i;
            int sectorIndex = sectors_[std::pair<int,int>(col,row)];
            sectorSizes_[sectorIndex].first += i;
            if (solve()) return true;
            data_[col][row] = 0;
            sectorSizes_[sectorIndex].first -= i;
        }
    }
    return false;
}

bool KillerBoard::canPlace(int col, int row, int num){
    int sectorIndex = sectors_[std::pair<int,int>(col,row)];
    return (!inCol(col, num) && !inRow(row, num) && !inZone(col, row, num) 
    && (sectorSizes_[sectorIndex].first + num <= sectorSizes_[sectorIndex].second));
}

void KillerBoard::printBoard(std::ofstream &file){
    for (int i=0; i<NUM; ++i){
        for (int j=0; j<NUM; ++j){
            if (j != NUM-1) file << data_[i][j] << " ";
            else file << data_[i][j] << std::endl;
        }
    }
}

void KillerBoard::loadBoard(std::ifstream &file){
    std::vector<int> temp(NUM, 0);
    for (int i=0; i<NUM; ++i) data_.push_back(temp);
    for (int i=0; i<NUM; ++i){
        for (int j=0; j<NUM; ++j){
            file >> data_[i][j];
        }
    }
    int x, y, sectorIndex, sectorMax;
    while (file >> y){
        file >> x;
        if (y < 0){
            sectorIndex = (-1*y)-1;
            sectorMax = x;
            sectorSizes_.push_back(std::pair<int,int>(0, sectorMax));
            continue;
        }
        sectors_[std::pair<int,int>(y,x)] = sectorIndex;
    }
}