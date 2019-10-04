#include <iostream>
#include "Alphabet.hpp"
#include "Character.hpp"
#include "String.hpp"
using namespace std;

int main(void) {
  Character char0(0);
  Character char1(1);
  Character char2(2);
  Character char3(3);
  cout << char0 << " " << char1 << " " << char2 << endl;

  Alphabet alpha;
  alpha.insert(char0);
  alpha.insert(char1);
  cout << alpha << endl;
  for (int i = 0; i < alpha.size(); i++) {
    cout << alpha[i] << endl;
  }

  String string(alpha);
  string.add(char0);
  string.add(char1);
  string.add(char1);
  string.add(char1);
  cout << string << endl;
  try {
    string.add(char3);
  } catch (const char* e) {
    cout << e << endl;
  }

  alpha.lexi(0);
  alpha.lexi(1);
  alpha.lexi(2);
  alpha.lexi(3);
  alpha.lexi(4);
  alpha.lexi(5);
  alpha.lexi(6);
  alpha.lexi(7);
  alpha.lexi(8);
  return 0;
}