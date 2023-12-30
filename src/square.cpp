
#include "../lib/square.hpp"

Square::Square() : color(BLACK) {}
Square::Square(bool color) : color(color) {}
Square::~Square() {}

void Square::set_color(bool color) { this->color = color; }
void Square::flip_color() {
  if (this->color == WHITE) {
    this->color = BLACK;
  } else {
    this->color = WHITE;
  }
}
bool Square::get_color() { return this->color; }

std::ostream &operator<<(std::ostream &out, const Square &square) {
  out << (square.color ? '+' : ' ');
  return out;
}