#ifndef __RegularBoard
#define __RegularBoard

#include <fstream>
#include <iostream>
#include <vector>

#include "board.h"

class RegularBoard : public Board {
 public:
  // Constructor
  RegularBoard(std::ifstream &file, char *size);
  // Constructor helper
  void loadBoard(std::ifstream &file);

  // Returns whether num can be placed at position (col, row)
  bool canPlace(int col, int row, int num);

  // Solver
  bool solve();
};

#endif