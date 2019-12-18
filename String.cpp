#include "String.hpp"
#include <iostream>
#include <stdexcept>
using namespace std;

void String::add(Character c) {
  if (_alpha.contains(c)) {
    _characters.push_back(c);
  } else {
    throw invalid_argument("Error: Your character is not in the alphabet");
  }
}

void String::pushfront(Character c) {
  if (_alpha.contains(c)) {
    vector<Character>::iterator it = _characters.begin();
    _characters.insert(it, c);
  } else {
    throw invalid_argument("Error: Your character is not in the alphabet");
  }
}

void String::pop_back() {
  if (_characters.size() > 0) {
    _characters.pop_back();
  } else {
    throw out_of_range("Index to pop_back is out of range");
  }
}

void String::pop_front() {
  if (_characters.size() > 0) {
    _characters.erase(_characters.begin());
  } else {
    throw out_of_range("Index to pop_front is out of range");
  }
}

Character String::front() {
  if (_characters.size() > 0) {
    return _characters[0];
  } else {
    throw out_of_range("Index to front is out of range");
  }
}

int String::length() { return _characters.size(); }

bool String::operator==(String right) {
  if (length() != right.length()) {
    return false;
  }
  for (int i = 0; i < static_cast<int>(length()); i++) {
    if (_characters[i] != right[i]) {
      return false;
    }
  }
  return true;
}

Character String::operator[](int i) {
  if (i < static_cast<int>(_characters.size())) {
    return _characters[i];
  } else {
    throw "Error: Out of range";
  }
}

ostream& operator<<(ostream& out, const String& string) {
  for (unsigned int i = 0; i < string._characters.size(); i++) {
    out << string._characters[i] << " ";
  }
  return out;
}