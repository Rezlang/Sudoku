#include "board.h"

//Returns true if num is in column col
bool Board::inCol(int col, int num){
    //iterate through spaces in column
    for (int r=0; r<NUM; ++r){
        //if space has value of num return true
        if (data_[col][r] == num) return true;
    }
    //if not in any of the spaces return false
    return false;
}

//Returns true if num is in row row
bool Board::inRow(int row, int num){
    //iterate through spaces in row
    for (int c=0; c<NUM; ++c){
        //if space has value of num return true
        if (data_[c][row] == num) return true;
    }
    //if not in any of the spaces return false
    return false;
}

//Returns true if num is in 3x3 zone
bool Board::inZone(int col, int row, int num){
    //iterate through all spaces in 3x3 zone
    for (int c = col/3*3; c < (col/3*3)+3; ++c){
        for (int r = row/3*3; r < (row/3*3) + 3; ++r){
            //if space has value of num return true
            if (data_[c][r] == num) return true;
        }
    }
    //if not in any of the spaces return false
    return false;
}

//returns true if there is an empty space remaining on board
//returns location by setting parameters by reference
bool Board::nextEmpty(int &col, int &row){
    for (col = 0; col<NUM; ++col){
        for (row = 0; row<NUM; ++row){
            //if current space is empty return true
            if (data_[col][row] == 0) return true;
        }
    }
    //return false if no empty spaces
    return false;
}

//prints board to output file supplied
void Board::printBoard(std::ofstream &file){
    //iterate through board positions
    for (int i=0; i<NUM; ++i){
        if (i%3 == 0) file << "|~-~-~-~-~-~-~-~-~-~-~-~|" << std::endl;
        for (int j=0; j<NUM; ++j){
            if (j == 0) file << "| ";
            if (j%3 == 0 && j != 0) file << "| ";
            std::string printChar = data_[i][j] == 0 ? " " : std::to_string(data_[i][j]);
            if (j != NUM-1) file << printChar << " ";
            else file << printChar << " |" <<std::endl;
        }
    }
    file << "|~-~-~-~-~-~-~-~-~-~-~-~|" << std::endl;
}