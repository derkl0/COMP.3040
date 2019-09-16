#include <iostream>
#include "Alphabet.hpp"
#include "Character.hpp"
using namespace std;

int main(void) {
  Character char0(0);
  Character char1(1);
  Character char2(2);
  cout << char0 << " " << char1 << " " << char2 << endl;

  Alphabet alpha;
  alpha.insert(char0);
  alpha.insert(char1);
  alpha.insert(char2);
  cout << alpha << endl;
  for (int i = 0; i < alpha.size(); i++) {
    cout << alpha[i] << endl;
  }
  return 0;
}