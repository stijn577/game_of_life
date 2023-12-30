#include "../lib/board.hpp"
#include "../lib/square.hpp"

#include <chrono>
#include <ctime>
#include <iostream>
#include <stdio.h>
#include <thread>
#include <vector>

Board::Board() {
  for (size_t row = 0; row < BOARD_SIZE; row++) {
    for (size_t col = 0; col < BOARD_SIZE; col++) {
      this->board[row][col] = Square();
    }
  }
}

std::ostream &operator<<(std::ostream &out, const Board &board) {
  std::cout << " _";
  for (int i = 0; i < BOARD_SIZE; i++) {
    std::cout << " _";
  }
  std::cout << "\n";

  for (size_t row = 0; row < BOARD_SIZE; row++) {
    std::cout << "| ";
    for (size_t col = 0; col < BOARD_SIZE; col++) {
      out << board.board[row][col] << " ";
    }
    std::cout << "|";
    out << "\n";
  }

  std::cout << "_";
  for (int i = 0; i < BOARD_SIZE; i++) {
    std::cout << " _";
  }
  std::cout << "\n";

  return out;
}

void Board::naive_update() {
  //   Board new_board = Board(*this);
  Square new_board[BOARD_SIZE][BOARD_SIZE] = {BLACK};

  for (int row = 0; row < BOARD_SIZE; row++) {

    for (int col = 0; col < BOARD_SIZE; col++) {
      int neighbors = this->get_neighbors(row, col);
      if (this->board[row][col].get_color() == WHITE) {
        if (neighbors == 2 || neighbors == 3) {
          new_board[row][col] = WHITE;
        } else {
          new_board[row][col] = BLACK;
        }
      } else {
        if (neighbors == 3) {
          new_board[row][col] = WHITE;
        } else {
          new_board[row][col] = BLACK;
        }
      }
    }
  }

  _sleep(500); // deprecated but im using older clang version

  this->set_board(new_board);
}

void Board::set_board(Square board[BOARD_SIZE][BOARD_SIZE]) {
  for (size_t row = 0; row < BOARD_SIZE; row++) {
    for (size_t col = 0; col < BOARD_SIZE; col++) {
      this->board[row][col] = board[row][col];
    }
  }
}

void Board::set_square_white(size_t row, size_t col) {
  if (row >= BOARD_SIZE || col >= BOARD_SIZE || row < 0 || col < 0) {
    printf("Error here");
    exit(1);
  }

  this->board[row][col].set_color(WHITE);
}

int Board::get_neighbors(size_t row, size_t col) {
  int left = -1;
  int right = 1;
  int bottom = -1;
  int top = 1;

  if (row == 0) {
    bottom = 0;
  } else if (row == BOARD_SIZE - 1) {
    top = 0;
  }
  if (col == 0) {
    left = 0;
  } else if (col == BOARD_SIZE - 1) {
    right = 0;
  }

  int neighbors = 0;
  for (int vertical = bottom; vertical <= top; vertical++) {
    for (int horizontal = left; horizontal <= right; horizontal++) {
      // FIXME: neighbors is never incremented even tho it should on index
      // (row, col ) == (1,4)
      if (horizontal != 0 || vertical != 0) {
        if (this->board[row + vertical][col + horizontal].get_color() ==
            WHITE) {
          neighbors++;
        }
      }
    }
  }

  return neighbors;
}