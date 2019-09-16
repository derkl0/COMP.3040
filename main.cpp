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
  alpha.insert(char2);
  cout << alpha << endl;
  for (int i = 0; i < alpha.size(); i++) {
    cout << alpha[i] << endl;
  }

  String string(alpha);
  string.add(char0);
  string.add(char1);
  string.add(char2);
  string.add(char1);
  string.add(char1);
  cout << string << endl;
  try {
    string.add(char3);
  } catch (const char* e) {
    cout << e << endl;
  }
  return 0;
}