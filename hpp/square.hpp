#pragma once

#include <iostream>

class Square {
private:
  bool color;

public:
  Square();
  Square(bool c);
  ~Square();

  void flip_color();
  void set_color(bool color);
  bool get_color();

  friend std::ostream &operator<<(std::ostream &os, const Square &dt);
};