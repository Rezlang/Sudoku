#ifndef __KBoard
#define __KBoard

#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <unordered_map>
#include <vector>

#include "board.h"

class KillerBoard : public Board {
 public:
  // Constructor
  KillerBoard(std::ifstream &file, char *size);
  // Constructor Helper
  void loadBoard(std::ifstream &file);

  // Returns whether num can be placed at position (col, row)
  bool canPlace(int col, int row, int num);

  // Solver
  bool solve();

 private:
  // key pair stores y coordinate and x coordinate
  // value pair stores index of sector in sectorSizes
  std::map<std::pair<int, int>, int> sectors_;

  // stors pair of current sector size and max sector size
  std::vector<std::pair<int, int> > sectorSizes_;
};

#endif