#include <functional>
#include <iostream>
#include "Alphabet.hpp"
#include "Character.hpp"
#include "DFA.hpp"
#include "String.hpp"
using namespace std;

bool test_lexi();
bool basicDFA();
bool oneCharDFA();
bool onlyEpsilon();
bool noStrings();
void init_globals();
DFA<int> charDFA(Character dfaChar) {
  DFA<int> dfa([](int qi) { return qi == 0 || qi == 1 || qi == 2; }, 0,
               [dfaChar](int qi, Character c) {
                 if (c == dfaChar && qi == 0) {
                   return 1;
                 } else {
                   return 2;
                 }
               },
               [](int qi) { return qi == 1; });
  return dfa;
}

Alphabet binaryAlpha;
Character char0(0);
Character char1(1);
Character char2(2);
Character char3(3);
String epsilon(binaryAlpha);
String test1(binaryAlpha);
String test2(binaryAlpha);
String test3(binaryAlpha);
String test4(binaryAlpha);
String test5(binaryAlpha);
String test6(binaryAlpha);
String test7(binaryAlpha);
String test8(binaryAlpha);
String test9(binaryAlpha);
String test10(binaryAlpha);
String test11(binaryAlpha);
String test12(binaryAlpha);
String test13(binaryAlpha);
String test14(binaryAlpha);
String test15(binaryAlpha);
String test16(binaryAlpha);

int main(void) {
  init_globals();
  int passed = 0;
  int failed = 0;
  test_lexi() ? passed++ : failed++;
  basicDFA() ? passed++ : failed++;
  oneCharDFA() ? passed++ : failed++;
  onlyEpsilon() ? passed++ : failed++;
  noStrings() ? passed++ : failed++;
  cout << "Tests: Passed: " << passed << " Failed: " << failed
       << " Total: " << passed + failed << endl;
  return 0;
}

void init_globals() {
  binaryAlpha.insert(char0);
  binaryAlpha.insert(char1);
  epsilon = String(binaryAlpha);
  test1 = binaryAlpha.lexi(1);
  test2 = binaryAlpha.lexi(2);
  test3 = binaryAlpha.lexi(3);
  test4 = binaryAlpha.lexi(4);
  test5 = binaryAlpha.lexi(5);
  test6 = binaryAlpha.lexi(6);
  test7 = binaryAlpha.lexi(7);
  test8 = binaryAlpha.lexi(8);
  test9 = binaryAlpha.lexi(9);
  test10 = binaryAlpha.lexi(10);
  test11 = binaryAlpha.lexi(11);
  test12 = binaryAlpha.lexi(12);
  test13 = binaryAlpha.lexi(13);
  test14 = binaryAlpha.lexi(14);
  test15 = binaryAlpha.lexi(15);
  test16 = binaryAlpha.lexi(16);
}

bool basicDFA() {
  int passed = 0;
  int failed = 0;
  DFA<int> basicDFA([](int qi) { return qi == 0 || qi == 1; }, 0,
                    [](int qi, Character c) {
                      if (qi == 0) {
                        return 1;
                      } else {
                        return 0;
                      }
                    },
                    [](int qi) { return qi == 0; });

  basicDFA.accepts(epsilon) == true ? passed++ : failed++;
  basicDFA.accepts(test1) == false ? passed++ : failed++;
  basicDFA.accepts(test3) == true ? passed++ : failed++;
  basicDFA.accepts(test13) == false ? passed++ : failed++;
  if (failed != 0) {
    cout << "Failed Basic DFA" << endl;
  }
  return failed == 0;
}

bool oneCharDFA() {
  int passed = 0;
  int failed = 0;
  DFA<int> onlyChar0 = charDFA(char0);

  onlyChar0.accepts(epsilon) == false ? passed++ : failed++;
  onlyChar0.accepts(test1) == true ? passed++ : failed++;
  onlyChar0.accepts(test2) == false ? passed++ : failed++;
  onlyChar0.accepts(test3) == false ? passed++ : failed++;
  onlyChar0.accepts(test4) == false ? passed++ : failed++;

  DFA<int> onlyChar1 = charDFA(char1);

  onlyChar1.accepts(epsilon) == false ? passed++ : failed++;
  onlyChar1.accepts(test1) == false ? passed++ : failed++;
  onlyChar1.accepts(test2) == true ? passed++ : failed++;
  onlyChar1.accepts(test3) == false ? passed++ : failed++;
  onlyChar1.accepts(test4) == false ? passed++ : failed++;
  if (failed != 0) {
    cout << "Failed onlyChar" << endl;
  }
  return failed == 0;
}

bool onlyEpsilon() {
  int passed = 0;
  int failed = 0;
  DFA<int> onlyEpsilon([](int qi) { return qi == 0 || qi == 1; }, 0,
                       [](int qi, Character c) { return 1; },
                       [](int qi) { return qi == 0; });

  onlyEpsilon.accepts(epsilon) == true ? passed++ : failed++;
  onlyEpsilon.accepts(test2) == false ? passed++ : failed++;
  onlyEpsilon.accepts(test3) == false ? passed++ : failed++;
  onlyEpsilon.accepts(test4) == false ? passed++ : failed++;
  if (failed != 0) {
    cout << "Failed onlyEpsilon" << endl;
  }
  return failed == 0;
}
bool noStrings() {
  int passed = 0;
  int failed = 0;
  DFA<int> noStrings([](int qi) { return qi == 0 || qi == 1; }, 0,
                     [](int qi, Character c) {
                       if (qi == 0) {
                         return 1;
                       } else {
                         return 0;
                       }
                     },
                     [](int qi) { return 0; });

  noStrings.accepts(epsilon) == false ? passed++ : failed++;
  noStrings.accepts(test2) == false ? passed++ : failed++;
  noStrings.accepts(test3) == false ? passed++ : failed++;
  noStrings.accepts(test4) == false ? passed++ : failed++;
  if (failed != 0) {
    cout << "Failed noStrings" << endl;
  }
  return failed == 0;
}

bool test_lexi() {
  int passed = 0;
  int failed = 0;
  binaryAlpha.lexi(0) == epsilon ? passed++ : failed++;
  binaryAlpha.lexi(1) == test1 ? passed++ : failed++;
  binaryAlpha.lexi(2) == test2 ? passed++ : failed++;
  binaryAlpha.lexi(3) == test3 ? passed++ : failed++;
  binaryAlpha.lexi(4) == test4 ? passed++ : failed++;
  binaryAlpha.lexi(5) == test5 ? passed++ : failed++;
  binaryAlpha.lexi(6) == test6 ? passed++ : failed++;
  binaryAlpha.lexi(7) == test7 ? passed++ : failed++;
  binaryAlpha.lexi(8) == test8 ? passed++ : failed++;
  if (failed != 0) {
    cout << "Failed lexi" << endl;
  }
  return failed == 0;
}