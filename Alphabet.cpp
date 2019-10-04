#include "Alphabet.hpp"
#include <cmath>
#include <iostream>
#include "String.hpp"
using namespace std;

void Alphabet::insert(Character c) { _characters.insert(c); }

int Alphabet::size() { return _characters.size(); }

bool Alphabet::contains(Character c) { return (bool)_characters.count(c); }

String Alphabet::lexi(int n) {
  String string(*this);
  if (n == 0) {
    return string;
  }
  int i;
  const int length = _characters.size();
  for (i = 0;; i++) {
    if (n >= pow(length, i)) {
      n -= pow(length, i);
    } else {
      break;
    }
  }
  for (int j = 0; j < i; j++) {
    string.pushfront(at(n % length));
    n = n / length;
  }
  return string;
}

Character Alphabet::at(int i) {
  set<Character>::iterator it = _characters.begin();
  advance(it, i);
  Character x = *it;
  return x;
}

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