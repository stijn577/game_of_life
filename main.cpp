#include "./lib/board.hpp"
#include "./lib/square.hpp"

int main(int argc, char *argv[]) {
  Board board = Board();

  board.set_square_black(1, 3);
  board.set_square_black(1, 4);
  board.set_square_black(1, 5);

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
}
