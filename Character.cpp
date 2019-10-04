#include "Character.hpp"
using namespace std;

ostream& operator<<(ostream& out, const Character& c) {
  out << c._c;
  return out;
}

bool operator<(Character left, Character right) { return left._c < right._c; }
bool operator>(Character left, Character right) { return left._c > right._c; }
bool operator==(Character left, Character right) { return left._c == right._c; }
bool operator!=(Character left, Character right) { return left._c != right._c; }