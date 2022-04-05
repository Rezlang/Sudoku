#ifndef __Board
#define __Board

#include <fstream>
#include <iostream>
#include <vector>

class Board {
 protected:
  // Constructor helper
  virtual void loadBoard(std::ifstream &file) = 0;
  // Main puzzle solver
  virtual bool solve() = 0;
  // Returns whether num can be placed at position (col, row)
  virtual bool canPlace(int col, int row, int num) = 0;
  // Getters and setters
  const int getNum(int col, int row) { return data_[col][row]; };
  void setNum(int col, int row, int num) { data_[col][row] = num; };

  // Helpers for canPlace
  bool inCol(int col, int num);
  bool inRow(int row, int num);
  bool inZone(int col, int row, int num);

  // Finds next tile on board that is empty (0 represents empty).
  // if all full returns true
  bool nextEmpty(int &col, int &row);

  // Stores grid data in 2d int vector
  std::vector<std::vector<int> > data_;
  int size_;

 public:
  // Representation
  void printBoard(std::ofstream &file);
};

#endif