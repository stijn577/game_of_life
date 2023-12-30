
#include "./lib/board.hpp"
#include "./lib/square.hpp"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  Board board = Board();

  board.set_square_white(4, 2);
  board.set_square_white(4, 3);
  board.set_square_white(4, 4);
  board.set_square_white(4, 5);
  board.set_square_white(4, 6);
  board.set_square_white(7, 2);
  board.set_square_white(7, 3);
  board.set_square_white(7, 7);
  board.set_square_white(7, 5);
  board.set_square_white(6, 2);
  board.set_square_white(6, 3);
  board.set_square_white(6, 7);
  board.set_square_white(7, 5);
  board.set_square_white(7, 6);
  board.set_square_white(0, 13);
  board.set_square_white(1, 12);
  board.set_square_white(2, 12);
  board.set_square_white(2, 13);
  board.set_square_white(2, 14);

  std::cout << board << std::endl;
  board.naive_update();
  std::cout << board << std::endl;
  board.naive_update();
  std::cout << board << std::endl;
  board.naive_update();
  std::cout << board << std::endl;
  board.naive_update();
  std::cout << board << std::endl;
  board.naive_update();
  std::cout << board << std::endl;
  board.naive_update();
  std::cout << board << std::endl;
  board.naive_update();
  std::cout << board << std::endl;
  board.naive_update();
  std::cout << board << std::endl;
  board.naive_update();
  std::cout << board << std::endl;
  board.naive_update();
  std::cout << board << std::endl;
  board.naive_update();
  std::cout << board << std::endl;
  board.naive_update();
  std::cout << board << std::endl;
  board.naive_update();
  std::cout << board << std::endl;
  board.naive_update();
  std::cout << board << std::endl;
  board.naive_update();
  std::cout << board << std::endl;
  board.naive_update();
  std::cout << board << std::endl;
  board.naive_update();
  std::cout << board << std::endl;


  return EXIT_SUCCESS;
}
