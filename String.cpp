#include "String.hpp"
#include <iostream>
using namespace std;

void String::add(Character c) {
  if (_alpha.contains(c)) {
    _characters.push_back(c);
  } else {
    throw "Error: Your character is not in the alphabet";
  }
}

void String::pushfront(Character c) {
  if (_alpha.contains(c)) {
    vector<Character>::iterator it = _characters.begin();
    _characters.insert(it, c);
  } else {
    throw "Error: Your character is not in the alphabet";
  }
}

Character String::front() {
  if (_characters.size() > 0) {
    return _characters[0];
  } else {
    throw "Error: Out of range";
  }
}

int String::length() { return _characters.size(); }
ostream& operator<<(ostream& out, const String& string) {
  for (unsigned int i = 0; i < string._characters.size(); i++) {
    out << string._characters[i];
  }
  return out;
}