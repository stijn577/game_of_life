#include "../hpp/board.hpp"
#include "../hpp/square.hpp"
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
  Square new_board[BOARD_SIZE][BOARD_SIZE];

  for (size_t row = 0; row < BOARD_SIZE; row++) {
    for (size_t col = 0; col < BOARD_SIZE; col++) {
      size_t neighbors = 0;
      for (size_t horizontal = -1; horizontal < 1; horizontal++) {
        for (size_t vertical = -1; vertical < 1; vertical++) {
          if (horizontal != 0 && vertical != 0 &&
              this->board[row + horizontal][col + vertical].get_color()) {
            neighbors++;
          }
        }
      }
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