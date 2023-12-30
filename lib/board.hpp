#pragma once

#include "../lib/square.hpp"
#include <ostream>
#include <vector>

const size_t BOARD_SIZE = 15;

class Board {
private:
  Square board[BOARD_SIZE][BOARD_SIZE];
  void set_board(Square board[BOARD_SIZE][BOARD_SIZE]);

public:
  Board();
  void set_square_white(size_t row, size_t col);

  void setup();
  void run(size_t n);

  int get_neighbors(size_t row, size_t col);
  void naive_update();

  void read_from_file(const char *filename);
  void write_to_file(const char *filename);
  friend std::ostream &operator<<(std::ostream &os, const Board &board);
};