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
  friend std::ostream &operator<<(std::ostream &os, const Board &board);
  void naive_update();
  void set_square_white(size_t row, size_t col);
  int get_neighbors(size_t row, size_t col);
};