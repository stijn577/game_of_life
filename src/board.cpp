#include "../lib/board.hpp"
#include "../lib/square.hpp"
#include <iostream>
#include <vector>

Board::Board() {
  for (size_t row = 0; row < BOARD_SIZE; row++) {
    for (size_t col = 0; col < BOARD_SIZE; col++) {
      this->board[row][col] = Square();
    }
  }
}

std::ostream &operator<<(std::ostream &out, const Board &board) {
  for (size_t row = 0; row < BOARD_SIZE; row++) {
    for (size_t col = 0; col < BOARD_SIZE; col++) {
      out << board.board[row][col] << " ";
    }
    out << "\n";
  }
  return out;
}

void Board::naive_update() {
  //   Board new_board = Board(*this);
  Square new_board[BOARD_SIZE][BOARD_SIZE];

  for (int row = 0; row < BOARD_SIZE; row++) {
    for (int col = 0; col < BOARD_SIZE; col++) {
      int neighbors = this->get_neighbors(row, col);
      if (neighbors == 2 || neighbors == 3) {
        new_board[row][col].set_color(true);
      } else {
        new_board[row][col].set_color(false);
      }
    }
  }
  this->set_board(new_board);
}

void Board::set_board(Square board[BOARD_SIZE][BOARD_SIZE]) {
  for (size_t row = 0; row < BOARD_SIZE; row++) {
    for (size_t col = 0; col < BOARD_SIZE; col++) {
      this->board[row][col] = board[row][col];
    }
  }
}

void Board::set_square_black(size_t row, size_t col) {
  if (row >= BOARD_SIZE || col >= BOARD_SIZE || row < 0 || col < 0) {
    exit(1);
  }

  this->board[row][col].set_color(true);
}

int Board::get_neighbors(size_t row, size_t col) {
  int left = -1;
  int right = 1;
  int bottom = -1;
  int top = 1;

  if (row == 0) {
    bottom = 0;
  } else if (row == 9) {
    top = 0;
  }
  if (col == 0) {
    left = 0;
  } else if (col == 9) {
    right = 0;
  }

  int neighbors = 0;
  for (int horizontal = left; horizontal <= right; horizontal++) {
    for (int vertical = bottom; vertical <= top; vertical++) {
      // FIXME: neighbors is never incremented even tho it should on index
      // (row, col ) == (1,4)
      if (row + vertical != 0 && col + horizontal != 0) {
        if (this->board[row + vertical][col + horizontal].get_color()) {
          neighbors++;
        }
      }
    }
  }

  return neighbors;
}