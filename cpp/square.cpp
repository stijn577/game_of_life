#include "../hpp/square.hpp"

Square::Square() : color(false) {}
Square::Square(bool color) : color(color) {}
Square::~Square() {}

void Square::set_color(bool color) { this->color = color; }
void Square::flip_color() {
  if (this->color) {
    this->color = false;
  } else {
    this->color = true;
  }
}
bool Square::get_color() { return this->color; }

std::ostream &operator<<(std::ostream &out, const Square &square) {
  out << (square.color ? "B" : "W");
  return out;
}