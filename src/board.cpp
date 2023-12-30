#include "../lib/board.hpp"
#include "../lib/square.hpp"

#include <chrono>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string>
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
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif

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

  return out;
}

void Board::naive_update() {
  // Initialise a new board with the board_size and set everything to black
  Square new_board[BOARD_SIZE][BOARD_SIZE] = {BLACK};

  for (int row = 0; row < BOARD_SIZE; row++) {

    for (int col = 0; col < BOARD_SIZE; col++) {
      int neighbors = this->get_neighbors(row, col);
      if (this->board[row][col].get_color() == WHITE) {
        if (neighbors == 2 || neighbors == 3) {
          new_board[row][col] = WHITE;
        }
        // since we default the new_board to be a fully BLACK field, only
        // BLACK->WHITE should be written else {
        //   new_board[row][col] = BLACK;
        // }
      } else {
        if (neighbors == 3) {
          new_board[row][col] = WHITE;
        }
        // since we default the new_board to be a fully BLACK field, only
        // BLACK->WHITE should be written else {
        //   new_board[row][col] = BLACK;
        // }
      }
    }
  }
#ifdef _WIN32
  _sleep(200); // deprecated but the newer version doesn't seem to work
#else
  std::this_thread::sleep_for(std::chrono::milliseconds(200));
#endif

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

void Board::setup() {
  this->set_square_white(4, 8);
  this->set_square_white(5, 8);
  this->set_square_white(6, 8);
  this->set_square_white(7, 8);
  this->set_square_white(8, 8);
}

void Board::run(size_t n) {
  for (size_t i = 0; i < n; i++) {
    std::cout << (*this) << std::endl;
    this->naive_update();
  }
}

void Board::write_to_file(const char *filename) {

  std::string file = "examples/";
  file.append(filename);
  file.append(".txt");

  std::ofstream OutputFile(file);

  std::cout << "Writing to file: " << file << std::endl;

  for (size_t row = 0; row < BOARD_SIZE; row++) {

    for (size_t col = 0; col < BOARD_SIZE; col++) {
      if (this->board[row][col].get_color() == WHITE) {
        OutputFile << '+';
      } else {
        OutputFile << '-';
      }
    }
    OutputFile << '\n';
  }

  OutputFile.close();
  // OutputFile << (*this);
}

void Board::read_from_file(const char *filename) {
  std::string file = "examples/";
  file.append(filename);
  file.append(".txt");

  std::cout << "Reading from: " << file << std::endl;

  Board new_board = Board();

  std::ifstream InputFile(file);

  std::string line;
  for (int row = 0; row < BOARD_SIZE; row++) {
    getline(InputFile, line, '\n');
    std::cout << line << std::endl;
    for (int col = 0; col < BOARD_SIZE; col++) {
      if (line[col] == '+') {
        new_board.board[row][col].set_color(WHITE);
      }
    }
  }

  InputFile.close();

  this->set_board(new_board.board);
}
