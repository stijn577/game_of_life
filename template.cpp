
#include "./lib/board.hpp"
#include "./lib/square.hpp"
#include <fstream>
#include <iostream>

int main(int argc, char *argv[]) {
  Board board = Board();

  board.setup();
  if (argc < 2) {
    board.write_to_file(argv[1]);
  }
  
  exit(0);
}