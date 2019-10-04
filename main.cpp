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
bool dfaTests();
void init_globals();
DFA<int> charDFA(Character dfaChar);

Alphabet binaryAlpha;
Alphabet alphabet;
Character char0(0);
Character char1(1);
Character char2(2);
Character char3(3);
Character _a(1);
Character _b(2);
Character _c(3);
Character _d(4);
Character _e(5);
Character _f(6);
Character _g(7);
Character _h(8);
Character _i(9);
Character _j(10);
Character _k(11);
Character _l(12);
Character _m(13);
Character _n(14);
Character _o(15);
Character _p(16);
Character _q(17);
Character _r(18);
Character _s(19);
Character _t(20);
Character _u(21);
Character _v(22);
Character _w(23);
Character _x(24);
Character _y(25);
Character _z(26);
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
  dfaTests() ? passed++ : failed++;
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
  alphabet.insert(_a);
  alphabet.insert(_b);
  alphabet.insert(_c);
  alphabet.insert(_d);
  alphabet.insert(_e);
  alphabet.insert(_f);
  alphabet.insert(_g);
  alphabet.insert(_h);
  alphabet.insert(_i);
  alphabet.insert(_j);
  alphabet.insert(_k);
  alphabet.insert(_l);
  alphabet.insert(_m);
  alphabet.insert(_n);
  alphabet.insert(_o);
  alphabet.insert(_p);
  alphabet.insert(_q);
  alphabet.insert(_r);
  alphabet.insert(_s);
  alphabet.insert(_t);
  alphabet.insert(_u);
  alphabet.insert(_v);
  alphabet.insert(_w);
  alphabet.insert(_x);
  alphabet.insert(_y);
  alphabet.insert(_z);
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

bool dfaTests() {
  int passed = 0;
  int failed = 0;
  DFA<int> acceptEvenNumbers([](int qi) { return qi == 0 || qi == 1; }, 0,
                             [](int qi, Character c) {
                               if (c == char1) {
                                 return 1;
                               } else {
                                 return 0;
                               }
                             },
                             [](int qi) { return qi == 0; });

  {
    acceptEvenNumbers.accepts(epsilon) == true ? passed++ : failed++;
    acceptEvenNumbers.accepts(test1) == true ? passed++ : failed++;
    acceptEvenNumbers.accepts(test2) == false ? passed++ : failed++;
    acceptEvenNumbers.accepts(test3) == true ? passed++ : failed++;
    acceptEvenNumbers.accepts(test4) == false ? passed++ : failed++;
    acceptEvenNumbers.accepts(test5) == true ? passed++ : failed++;
    acceptEvenNumbers.accepts(test6) == false ? passed++ : failed++;
    acceptEvenNumbers.accepts(test7) == true ? passed++ : failed++;
    acceptEvenNumbers.accepts(test8) == false ? passed++ : failed++;
    acceptEvenNumbers.accepts(test9) == true ? passed++ : failed++;
    acceptEvenNumbers.accepts(test10) == false ? passed++ : failed++;
    acceptEvenNumbers.accepts(test11) == true ? passed++ : failed++;
    acceptEvenNumbers.accepts(test12) == false ? passed++ : failed++;
    acceptEvenNumbers.accepts(test13) == true ? passed++ : failed++;
    acceptEvenNumbers.accepts(test14) == false ? passed++ : failed++;
    acceptEvenNumbers.accepts(test15) == true ? passed++ : failed++;
    acceptEvenNumbers.accepts(test16) == false ? passed++ : failed++;
  }

  DFA<int> acceptEvenLength([](int qi) { return qi == 0 || qi == 1; }, 0,
                            [](int qi, Character c) {
                              if (qi == 0) {
                                return 1;
                              } else {
                                return 0;
                              }
                            },
                            [](int qi) { return qi == 0; });
  {
    acceptEvenLength.accepts(epsilon) == true ? passed++ : failed++;
    acceptEvenLength.accepts(test1) == false ? passed++ : failed++;
    acceptEvenLength.accepts(test2) == false ? passed++ : failed++;
    acceptEvenLength.accepts(test3) == true ? passed++ : failed++;
    acceptEvenLength.accepts(test4) == true ? passed++ : failed++;
    acceptEvenLength.accepts(test5) == true ? passed++ : failed++;
    acceptEvenLength.accepts(test6) == true ? passed++ : failed++;
    acceptEvenLength.accepts(test7) == false ? passed++ : failed++;
    acceptEvenLength.accepts(test8) == false ? passed++ : failed++;
    acceptEvenLength.accepts(test9) == false ? passed++ : failed++;
    acceptEvenLength.accepts(test10) == false ? passed++ : failed++;
    acceptEvenLength.accepts(test11) == false ? passed++ : failed++;
    acceptEvenLength.accepts(test12) == false ? passed++ : failed++;
    acceptEvenLength.accepts(test13) == false ? passed++ : failed++;
    acceptEvenLength.accepts(test14) == false ? passed++ : failed++;
    acceptEvenLength.accepts(test15) == true ? passed++ : failed++;
    acceptEvenLength.accepts(test16) == true ? passed++ : failed++;
  }

  DFA<char> acceptWithJason(
      [](char qi) {
        return qi == '!' || qi == 'J' || qi == 'A' || qi == 'S' || qi == 'O' ||
               qi == 'N';
      },
      '!',
      [](char qi, Character c) {
        switch (qi) {
          case 'J':
            return c == _a ? 'A' : '!';
          case 'A':
            return c == _s ? 'S' : '!';
          case 'S':
            return c == _o ? 'N' : '!';
          case 'O':
            return c == _n ? 'N' : '!';
          case 'N':
            return 'N';
          default:
            return c == _j ? 'J' : '!';
        }
      },
      [](char qi) { return qi == 'N'; });
  String jason(alphabet);
  {
    jason.add(_j);
    jason.add(_a);
    jason.add(_s);
    jason.add(_o);
    jason.add(_n);
  }
  String jasonkiesling(alphabet);
  {
    jasonkiesling.add(_j);
    jasonkiesling.add(_a);
    jasonkiesling.add(_s);
    jasonkiesling.add(_o);
    jasonkiesling.add(_n);
    jasonkiesling.add(_k);
    jasonkiesling.add(_i);
    jasonkiesling.add(_e);
    jasonkiesling.add(_s);
    jasonkiesling.add(_l);
    jasonkiesling.add(_i);
    jasonkiesling.add(_e);
    jasonkiesling.add(_s);
    jasonkiesling.add(_l);
    jasonkiesling.add(_i);
    jasonkiesling.add(_n);
    jasonkiesling.add(_g);
  }

  String fjasont(alphabet);
  {
    fjasont.add(_f);
    fjasont.add(_j);
    fjasont.add(_a);
    fjasont.add(_s);
    fjasont.add(_o);
    fjasont.add(_n);
    fjasont.add(_t);
  }

  String jasonjason(alphabet);
  {
    jasonjason.add(_j);
    jasonjason.add(_a);
    jasonjason.add(_s);
    jasonjason.add(_o);
    jasonjason.add(_n);
    jasonjason.add(_j);
    jasonjason.add(_a);
    jasonjason.add(_s);
    jasonjason.add(_o);
    jasonjason.add(_n);
  }

  String jasonjasjason(alphabet);
  {
    jasonjasjason.add(_j);
    jasonjasjason.add(_a);
    jasonjasjason.add(_s);
    jasonjasjason.add(_o);
    jasonjasjason.add(_n);
    jasonjasjason.add(_j);
    jasonjasjason.add(_a);
    jasonjasjason.add(_s);
    jasonjasjason.add(_j);
    jasonjasjason.add(_a);
    jasonjasjason.add(_s);
    jasonjasjason.add(_o);
    jasonjasjason.add(_n);
  }

  String jsonkiesling(alphabet);
  {
    jasonkiesling.add(_j);
    jasonkiesling.add(_a);
    jasonkiesling.add(_o);
    jasonkiesling.add(_n);
    jasonkiesling.add(_k);
    jasonkiesling.add(_i);
    jasonkiesling.add(_e);
    jasonkiesling.add(_s);
    jasonkiesling.add(_l);
    jasonkiesling.add(_i);
    jasonkiesling.add(_e);
    jasonkiesling.add(_s);
    jasonkiesling.add(_l);
    jasonkiesling.add(_i);
    jasonkiesling.add(_n);
    jasonkiesling.add(_g);
  }

  String jasondkiesling(alphabet);
  {
    jasondkiesling.add(_j);
    jasondkiesling.add(_a);
    jasondkiesling.add(_s);
    jasondkiesling.add(_o);
    jasondkiesling.add(_n);
    jasondkiesling.add(_d);
    jasondkiesling.add(_k);
    jasondkiesling.add(_i);
    jasondkiesling.add(_e);
    jasondkiesling.add(_s);
    jasondkiesling.add(_l);
    jasondkiesling.add(_i);
    jasondkiesling.add(_e);
    jasondkiesling.add(_s);
    jasondkiesling.add(_l);
    jasondkiesling.add(_i);
    jasondkiesling.add(_n);
    jasondkiesling.add(_g);
  }

  {
    acceptWithJason.accepts(jason) == true ? passed++ : failed++;
    acceptWithJason.accepts(jasonkiesling) == true ? passed++ : failed++;
    acceptWithJason.accepts(fjasont) == true ? passed++ : failed++;
    acceptWithJason.accepts(jasonjason) == true ? passed++ : failed++;
    acceptWithJason.accepts(jasonjasjason) == true ? passed++ : failed++;
    acceptWithJason.accepts(jasondkiesling) == true ? passed++ : failed++;

    acceptWithJason.accepts(jsonkiesling) == false ? passed++ : failed++;
    acceptWithJason.accepts(epsilon) == false ? passed++ : failed++;
    acceptWithJason.accepts(test1) == false ? passed++ : failed++;
    acceptWithJason.accepts(test2) == false ? passed++ : failed++;
    acceptWithJason.accepts(test3) == false ? passed++ : failed++;
    acceptWithJason.accepts(test4) == false ? passed++ : failed++;
  }
  if (failed != 0) {
    cout << "Failed " << failed << " DFA tests" << endl;
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