#ifndef ALPHABET_HPP
#define ALPHABET_HPP

#include <set>
#include "Character.hpp"

class Alphabet {
 public:
  void insert(Character c);
  int size();

  Character operator[](int i);
  friend std::ostream& operator<<(std::ostream& out, const Alphabet& alpha);

 private:
  std::set<Character> _characters;
};

#endif