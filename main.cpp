#pragma once

#include "./lib/board.hpp"

int main(int argc, char *argv[]) {
  Board board = Board();

  board.setup();
  if (argc == 2) {
    board.read_from_file(argv[1]);
  }

  board.run(20);

  exit(0);
}
