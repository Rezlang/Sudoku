#include "KillerBoard.h"
#include "regularBoard.h"

int main(int argc, char* argv[]) {
  if (argc != 5) {
    std::cerr << "Invalid Arguments." << std::endl
              << "Correct Usage: <input file> <output file> <killer/regular> "
                 "<width of board>"
              << std::endl;
    return 1;
  }
  std::ifstream inFile;
  inFile.open(argv[1]);
  if (!inFile) {
    std::cerr << "error opening input file" << std::endl;
    return 2;
  }
  std::ofstream outFile;
  outFile.open(argv[2]);
  if (!outFile) {
    std::cerr << "error opening output file" << std::endl;
    return 3;
  }

  std::string runType = std::string(argv[3]);
  RegularBoard sudoku = RegularBoard(inFile, argv[4]);

  outFile << "Mode: " << runType << std::endl << std::endl;
  if (runType.compare("killer") == 0)
    KillerBoard sudoku = KillerBoard(inFile, argv[4]);
  outFile << "Original Board:" << std::endl;
  sudoku.printBoard(outFile);
  outFile << std::endl << "Solving Board..." << std::endl;

  if (!sudoku.solve()) {
    outFile << std::endl << "No solution for given board" << std::endl;
  }

  else {
    outFile << std::endl << "Solved Board:" << std::endl;
    sudoku.printBoard(outFile);
  }
  outFile.close();

  return 0;
}