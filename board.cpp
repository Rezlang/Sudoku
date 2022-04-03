#include "board.h"

bool Board::inCol(int col, int num){
    for (int r=0; r<NUM; ++r){
        if (data_[col][r] == num) return true;
    }
    return false;
}

bool Board::inRow(int row, int num){
    for (int c=0; c<NUM; ++c){
        if (data_[c][row] == num) return true;
    }
    return false;
}

bool Board::inZone(int col, int row, int num){
    for (int c = col/3*3; c < (col/3*3)+3; ++c){
        for (int r = row/3*3; r < (row/3*3) + 3; ++r){
            if (data_[c][r] == num) return true;
        }
    }
    return false;
}

bool Board::nextEmpty(int &col, int &row){
    for (col = 0; col<NUM; ++col){
        for (row = 0; row<NUM; ++row){
            if (data_[col][row] == 0) return true;
        }
    }
    return false;
}

bool Board::solve(){
    int col, row;
    if (!nextEmpty(col, row)) return true;
    for (int i=1; i<=NUM; ++i){
        if (canPlace(col, row, i)){
            data_[col][row] = i;
            if (solve()) return true;
            data_[col][row] = 0;
        }
    }
    return false;
}

bool Board::canPlace(int col, int row, int num){
    return (!inCol(col, num) && !inRow(row, num) && !inZone(col, row, num));
}

void Board::printBoard(std::ofstream &file){
    for (int i=0; i<NUM; ++i){
        for (int j=0; j<NUM; ++j){
            if (j != NUM-1) file << data_[i][j] << " ";
            else file << data_[i][j] << std::endl;
        }
    }
}

void Board::loadBoard(std::ifstream &file){
    std::vector<int> temp;
    int x;
    while (file >> x){
        temp.push_back(x);
        if (temp.size() == NUM){
            data_.push_back(temp);
            temp.clear();
        }
    }
}