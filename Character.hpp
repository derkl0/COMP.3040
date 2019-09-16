#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>

class Character {
 public:
  Character(int c) { _c = c; }
  friend std::ostream& operator<<(std::ostream& out, const Character& c);
  friend bool operator<(Character left, Character right);
  friend bool operator>(Character left, Character right);
  friend bool operator==(Character left, Character right);

 private:
  int _c;
};

#endif