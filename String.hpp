#ifndef STRING_HPP
#define STRING_HPP

#include <vector>
#include "Alphabet.hpp"
#include "Character.hpp"

class String {
 public:
  String(Alphabet alpha) { _alpha = alpha; }
  void add(Character c);
  void pushfront(Character c);
  Character front();
  int length();
  friend std::ostream& operator<<(std::ostream& out, const String& string);
  Character operator[](int i);
  bool operator==(String right);

 private:
  Alphabet _alpha;
  std::vector<Character> _characters;
};

#endif