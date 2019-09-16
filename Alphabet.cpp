#include "Alphabet.hpp"
#include <iostream>
using namespace std;

void Alphabet::insert(Character c) { _characters.insert(c); }

int Alphabet::size() { return _characters.size(); }

bool Alphabet::contains(Character c) { return (bool)_characters.count(c); }

Character Alphabet::operator[](int i) {
  set<Character>::iterator it = _characters.begin();
  advance(it, i);
  Character x = *it;
  return x;
}

ostream& operator<<(ostream& out, const Alphabet& alpha) {
  for (set<Character>::iterator it = alpha._characters.begin();
       it != alpha._characters.end(); it++) {
    out << *it << " ";
  }
  return out;
}