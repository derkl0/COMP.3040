#include <functional>
#include <iostream>
#include <utility>
#include <vector>
#include "Alphabet.hpp"
#include "Character.hpp"
#include "DFA.hpp"
#include "NFA.hpp"
#include "String.hpp"
using namespace std;

bool test_lexi();
bool basicDFA();
bool oneCharDFA();
bool onlyEpsilon();
bool noStrings();
bool dfaTests();
bool test_dfa_accepts_string();
bool test_accepted_states();
bool test_find_strings();
bool test_inverse_dfa();
bool test_union_dfa();
bool test_intersect_dfa();
bool test_subset_dfa();
bool test_equal_dfa();
bool test_manual_equal_dfa();
bool test_nfa();

void init_globals();

DFA<int> charDFA(Character dfaChar);

template <typename T>
bool is_accepted_in_dfa(DFA<T> dfa, String string);

template <typename T>
vector<pair<T, Character>> accepted_states(DFA<T> dfa, String string);

template <typename T>
String find_string(DFA<T> dfa, Alphabet alpha);

template <typename T>
DFA<T> inverse_dfa(DFA<T> dfa);

template <typename T1, typename T2>
DFA<pair<T1, T2>> union_dfa(DFA<T1> dfa1, DFA<T2> dfa2);

template <typename T1, typename T2>
DFA<pair<T1, T2>> intersect_dfa(DFA<T1> dfa1, DFA<T2> dfa2);

template <typename T1, typename T2>
bool subset_dfa(DFA<T1> x, DFA<T2> y, Alphabet alpha);

template <typename T1, typename T2>
bool equal_dfa(DFA<T1> x, DFA<T2> y, Alphabet alpha);

Alphabet binaryAlpha;
Alphabet alphabet;
Character _epsilon(-1);
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
  test_dfa_accepts_string() ? passed++ : failed++;
  test_accepted_states() ? passed++ : failed++;
  test_find_strings() ? passed++ : failed++;
  test_inverse_dfa() ? passed++ : failed++;
  test_union_dfa() ? passed++ : failed++;
  test_intersect_dfa() ? passed++ : failed++;
  test_subset_dfa() ? passed++ : failed++;
  test_equal_dfa() ? passed++ : failed++;
  test_manual_equal_dfa() ? passed++ : failed++;
  test_nfa() ? passed++ : failed++;
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
            return c == _o ? 'O' : '!';
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

bool test_dfa_accepts_string() {
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
    is_accepted_in_dfa(acceptEvenNumbers, epsilon) == true ? passed++
                                                           : failed++;
    is_accepted_in_dfa(acceptEvenNumbers, test1) == true ? passed++ : failed++;
    is_accepted_in_dfa(acceptEvenNumbers, test2) == false ? passed++ : failed++;
    is_accepted_in_dfa(acceptEvenNumbers, test3) == true ? passed++ : failed++;
    is_accepted_in_dfa(acceptEvenNumbers, test4) == false ? passed++ : failed++;
    is_accepted_in_dfa(acceptEvenNumbers, test5) == true ? passed++ : failed++;
    is_accepted_in_dfa(acceptEvenNumbers, test6) == false ? passed++ : failed++;
    is_accepted_in_dfa(acceptEvenNumbers, test7) == true ? passed++ : failed++;
    is_accepted_in_dfa(acceptEvenNumbers, test8) == false ? passed++ : failed++;
    is_accepted_in_dfa(acceptEvenNumbers, test9) == true ? passed++ : failed++;
    is_accepted_in_dfa(acceptEvenNumbers, test10) == false ? passed++
                                                           : failed++;
    is_accepted_in_dfa(acceptEvenNumbers, test11) == true ? passed++ : failed++;
    is_accepted_in_dfa(acceptEvenNumbers, test12) == false ? passed++
                                                           : failed++;
    is_accepted_in_dfa(acceptEvenNumbers, test13) == true ? passed++ : failed++;
    is_accepted_in_dfa(acceptEvenNumbers, test14) == false ? passed++
                                                           : failed++;
    is_accepted_in_dfa(acceptEvenNumbers, test15) == true ? passed++ : failed++;
    is_accepted_in_dfa(acceptEvenNumbers, test16) == false ? passed++
                                                           : failed++;
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
    is_accepted_in_dfa(acceptEvenLength, epsilon) == true ? passed++ : failed++;
    is_accepted_in_dfa(acceptEvenLength, test1) == false ? passed++ : failed++;
    is_accepted_in_dfa(acceptEvenLength, test2) == false ? passed++ : failed++;
    is_accepted_in_dfa(acceptEvenLength, test3) == true ? passed++ : failed++;
    is_accepted_in_dfa(acceptEvenLength, test4) == true ? passed++ : failed++;
    is_accepted_in_dfa(acceptEvenLength, test5) == true ? passed++ : failed++;
    is_accepted_in_dfa(acceptEvenLength, test6) == true ? passed++ : failed++;
    is_accepted_in_dfa(acceptEvenLength, test7) == false ? passed++ : failed++;
    is_accepted_in_dfa(acceptEvenLength, test8) == false ? passed++ : failed++;
    is_accepted_in_dfa(acceptEvenLength, test9) == false ? passed++ : failed++;
    is_accepted_in_dfa(acceptEvenLength, test10) == false ? passed++ : failed++;
    is_accepted_in_dfa(acceptEvenLength, test11) == false ? passed++ : failed++;
    is_accepted_in_dfa(acceptEvenLength, test12) == false ? passed++ : failed++;
    is_accepted_in_dfa(acceptEvenLength, test13) == false ? passed++ : failed++;
    is_accepted_in_dfa(acceptEvenLength, test14) == false ? passed++ : failed++;
    is_accepted_in_dfa(acceptEvenLength, test15) == true ? passed++ : failed++;
    is_accepted_in_dfa(acceptEvenLength, test16) == true ? passed++ : failed++;
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
            return c == _o ? 'O' : '!';
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
    is_accepted_in_dfa(acceptWithJason, jason) == true ? passed++ : failed++;
    is_accepted_in_dfa(acceptWithJason, jasonkiesling) == true ? passed++
                                                               : failed++;
    is_accepted_in_dfa(acceptWithJason, fjasont) == true ? passed++ : failed++;
    is_accepted_in_dfa(acceptWithJason, jasonjason) == true ? passed++
                                                            : failed++;
    is_accepted_in_dfa(acceptWithJason, jasonjasjason) == true ? passed++
                                                               : failed++;
    is_accepted_in_dfa(acceptWithJason, jasondkiesling) == true ? passed++
                                                                : failed++;

    is_accepted_in_dfa(acceptWithJason, jsonkiesling) == false ? passed++
                                                               : failed++;
    is_accepted_in_dfa(acceptWithJason, epsilon) == false ? passed++ : failed++;
    is_accepted_in_dfa(acceptWithJason, test1) == false ? passed++ : failed++;
    is_accepted_in_dfa(acceptWithJason, test2) == false ? passed++ : failed++;
    is_accepted_in_dfa(acceptWithJason, test3) == false ? passed++ : failed++;
    is_accepted_in_dfa(acceptWithJason, test4) == false ? passed++ : failed++;
  }

  if (failed != 0) {
    cout << "Failed " << failed << "DFA accepts string tests" << endl;
  }
  return failed == 0;
}

template <typename T>
bool is_accepted_in_dfa(DFA<T> dfa, String string) {
  return dfa.accepts(string);
}

bool test_accepted_states() {
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

  vector<pair<int, Character>> result =
      acceptEvenNumbers.accepts_with_states(epsilon);
  vector<pair<int, Character>> answer;
  if (result.size() == answer.size()) {
    for (int i = 0; i < static_cast<int>(result.size()); i++) {
      if (result[i].first != answer[i].first ||
          result[i].second != answer[i].second) {
        failed++;
        break;
      }
    }
    passed++;
  }

  result = acceptEvenNumbers.accepts_with_states(test1);
  answer.push_back(pair<int, Character>(0, char0));
  if (result.size() == answer.size()) {
    for (int i = 0; i < static_cast<int>(result.size()); i++) {
      if (result[i].first != answer[i].first ||
          result[i].second != answer[i].second) {
        failed++;
        break;
      }
    }
    passed++;
  } else {
    failed++;
  }

  answer.clear();
  result = acceptEvenNumbers.accepts_with_states(test2);
  answer.push_back(pair<int, Character>(1, char1));
  if (result.size() == answer.size()) {
    for (int i = 0; i < static_cast<int>(result.size()); i++) {
      if (result[i].first != answer[i].first ||
          result[i].second != answer[i].second) {
        failed++;
        break;
      }
    }
    passed++;
  } else {
    failed++;
  }

  answer.clear();
  result = acceptEvenNumbers.accepts_with_states(test3);
  answer.push_back(pair<int, Character>(0, char0));
  answer.push_back(pair<int, Character>(0, char0));
  if (result.size() == answer.size()) {
    for (int i = 0; i < static_cast<int>(result.size()); i++) {
      if (result[i].first != answer[i].first ||
          result[i].second != answer[i].second) {
        failed++;
        break;
      }
    }
    passed++;
  } else {
    failed++;
  }

  answer.clear();
  result = acceptEvenNumbers.accepts_with_states(test4);
  answer.push_back(pair<int, Character>(0, char0));
  answer.push_back(pair<int, Character>(1, char1));
  if (result.size() == answer.size()) {
    for (int i = 0; i < static_cast<int>(result.size()); i++) {
      if (result[i].first != answer[i].first ||
          result[i].second != answer[i].second) {
        failed++;
        break;
      }
    }
    passed++;
  } else {
    failed++;
  }

  if (failed != 0) {
    cout << "Failed " << failed << " tests with accepted state pairs" << endl;
  }
  return failed == 0;
}

template <typename T>
vector<pair<T, Character>> accepted_states(DFA<T> dfa, String string) {
  return dfa.accepts_with_states(dfa, string);
}

bool test_find_strings() {
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
  String string = find_string(acceptEvenNumbers, binaryAlpha);
  String answer(binaryAlpha);
  if (string.length() == answer.length()) {
    for (int i = 0; i < string.length(); i++) {
      if (string[i] != answer[i]) {
        failed++;
        break;
      }
    }
    passed++;
  } else {
    failed++;
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
            return c == _o ? 'O' : '!';
          case 'O':
            return c == _n ? 'N' : '!';
          case 'N':
            return 'N';
          default:
            return c == _j ? 'J' : '!';
        }
      },
      [](char qi) { return qi == 'N'; });
  String answer2(alphabet);
  answer2.add(_j);
  answer2.add(_a);
  answer2.add(_s);
  answer2.add(_o);
  answer2.add(_n);
  string = find_string(acceptWithJason, alphabet);
  if (string.length() == answer2.length()) {
    for (int i = 0; i < string.length(); i++) {
      if (string[i] != answer2[i]) {
        failed++;
        break;
      }
    }
    passed++;
  } else {
    failed++;
  }

  DFA<int> acceptNothing([](int qi) { return qi == 0; }, 0,
                         [](int qi, Character c) { return 0; },
                         [](int qi) { return 0; });
  string = find_string(acceptNothing, binaryAlpha);
  String answer3(binaryAlpha);
  if (string.length() == answer3.length()) {
    for (int i = 0; i < string.length(); i++) {
      if (string[i] != answer3[i]) {
        failed++;
        break;
      }
    }
    passed++;
  } else {
    failed++;
  }

  if (failed != 0) {
    cout << "Failed " << failed << " tests to find string" << endl;
  }
  return failed == 0;
}

template <typename T>
String find_string(DFA<T> dfa, Alphabet alpha) {
  return dfa.find_string(alpha);
}

bool test_inverse_dfa() {
  int failed = 0;
  int passed = 0;

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
    DFA<int> acceptEvenNumbersInverse = inverse_dfa(acceptEvenNumbers);
    acceptEvenNumbersInverse.accepts(epsilon) == false ? passed++ : failed++;
    acceptEvenNumbersInverse.accepts(test1) == false ? passed++ : failed++;
    acceptEvenNumbersInverse.accepts(test2) == true ? passed++ : failed++;
    acceptEvenNumbersInverse.accepts(test3) == false ? passed++ : failed++;
    acceptEvenNumbersInverse.accepts(test4) == true ? passed++ : failed++;
    acceptEvenNumbersInverse.accepts(test5) == false ? passed++ : failed++;
    acceptEvenNumbersInverse.accepts(test6) == true ? passed++ : failed++;
    acceptEvenNumbersInverse.accepts(test7) == false ? passed++ : failed++;
    acceptEvenNumbersInverse.accepts(test8) == true ? passed++ : failed++;
    acceptEvenNumbersInverse.accepts(test9) == false ? passed++ : failed++;
    acceptEvenNumbersInverse.accepts(test10) == true ? passed++ : failed++;
    acceptEvenNumbersInverse.accepts(test11) == false ? passed++ : failed++;
    acceptEvenNumbersInverse.accepts(test12) == true ? passed++ : failed++;
    acceptEvenNumbersInverse.accepts(test13) == false ? passed++ : failed++;
    acceptEvenNumbersInverse.accepts(test14) == true ? passed++ : failed++;
    acceptEvenNumbersInverse.accepts(test15) == false ? passed++ : failed++;
    acceptEvenNumbersInverse.accepts(test16) == true ? passed++ : failed++;
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
    DFA<int> acceptEvenLengthInverse = inverse_dfa(acceptEvenLength);
    acceptEvenLengthInverse.accepts(epsilon) == false ? passed++ : failed++;
    acceptEvenLengthInverse.accepts(test1) == true ? passed++ : failed++;
    acceptEvenLengthInverse.accepts(test2) == true ? passed++ : failed++;
    acceptEvenLengthInverse.accepts(test3) == false ? passed++ : failed++;
    acceptEvenLengthInverse.accepts(test4) == false ? passed++ : failed++;
    acceptEvenLengthInverse.accepts(test5) == false ? passed++ : failed++;
    acceptEvenLengthInverse.accepts(test6) == false ? passed++ : failed++;
    acceptEvenLengthInverse.accepts(test7) == true ? passed++ : failed++;
    acceptEvenLengthInverse.accepts(test8) == true ? passed++ : failed++;
    acceptEvenLengthInverse.accepts(test9) == true ? passed++ : failed++;
    acceptEvenLengthInverse.accepts(test10) == true ? passed++ : failed++;
    acceptEvenLengthInverse.accepts(test11) == true ? passed++ : failed++;
    acceptEvenLengthInverse.accepts(test12) == true ? passed++ : failed++;
    acceptEvenLengthInverse.accepts(test13) == true ? passed++ : failed++;
    acceptEvenLengthInverse.accepts(test14) == true ? passed++ : failed++;
    acceptEvenLengthInverse.accepts(test15) == false ? passed++ : failed++;
    acceptEvenLengthInverse.accepts(test16) == false ? passed++ : failed++;
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
            return c == _o ? 'O' : '!';
          case 'O':
            return c == _n ? 'N' : '!';
          case 'N':
            return 'N';
          default:
            return c == _j ? 'J' : '!';
        }
      },
      [](char qi) { return qi == 'N'; });
  DFA<char> acceptWithJasonInverse = inverse_dfa(acceptWithJason);
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
    acceptWithJasonInverse.accepts(jason) == false ? passed++ : failed++;
    acceptWithJasonInverse.accepts(jasonkiesling) == false ? passed++
                                                           : failed++;
    acceptWithJasonInverse.accepts(fjasont) == false ? passed++ : failed++;
    acceptWithJasonInverse.accepts(jasonjason) == false ? passed++ : failed++;
    acceptWithJasonInverse.accepts(jasonjasjason) == false ? passed++
                                                           : failed++;
    acceptWithJasonInverse.accepts(jasondkiesling) == false ? passed++
                                                            : failed++;

    acceptWithJasonInverse.accepts(jsonkiesling) == true ? passed++ : failed++;
    acceptWithJasonInverse.accepts(epsilon) == true ? passed++ : failed++;
    acceptWithJasonInverse.accepts(test1) == true ? passed++ : failed++;
    acceptWithJasonInverse.accepts(test2) == true ? passed++ : failed++;
    acceptWithJasonInverse.accepts(test3) == true ? passed++ : failed++;
    acceptWithJasonInverse.accepts(test4) == true ? passed++ : failed++;
  }

  if (failed != 0) {
    cout << "Failed " << failed << "DFA inverse" << endl;
  }
  return failed == 0;
}

template <typename T>
DFA<T> inverse_dfa(DFA<T> dfa) {
  function<bool(T)> Fprime = [dfa](T qi) { return !dfa.F(qi); };
  DFA<T> returnDFA(dfa.Q, dfa.q0, dfa.Delta, Fprime);
  return returnDFA;
}

bool test_union_dfa() {
  int failed = 0;
  int passed = 0;

  DFA<int> acceptEvenNumbers([](int qi) { return qi == 0 || qi == 1; }, 0,
                             [](int qi, Character c) {
                               if (c == char1) {
                                 return 1;
                               } else {
                                 return 0;
                               }
                             },
                             [](int qi) { return qi == 0; });

  DFA<int> acceptEvenLength([](int qi) { return qi == 0 || qi == 1; }, 0,
                            [](int qi, Character c) {
                              if (qi == 0) {
                                return 1;
                              } else {
                                return 0;
                              }
                            },
                            [](int qi) { return qi == 0; });

  DFA<pair<int, int>> unionDFA = union_dfa(acceptEvenNumbers, acceptEvenLength);

  {
    unionDFA.accepts(epsilon) == true ? passed++ : failed++;
    unionDFA.accepts(test1) == true ? passed++ : failed++;
    unionDFA.accepts(test2) == false ? passed++ : failed++;
    unionDFA.accepts(test3) == true ? passed++ : failed++;
    unionDFA.accepts(test4) == true ? passed++ : failed++;
    unionDFA.accepts(test5) == true ? passed++ : failed++;
    unionDFA.accepts(test6) == true ? passed++ : failed++;
    unionDFA.accepts(test7) == true ? passed++ : failed++;
    unionDFA.accepts(test8) == false ? passed++ : failed++;
    unionDFA.accepts(test9) == true ? passed++ : failed++;
    unionDFA.accepts(test10) == false ? passed++ : failed++;
    unionDFA.accepts(test11) == true ? passed++ : failed++;
    unionDFA.accepts(test12) == false ? passed++ : failed++;
    unionDFA.accepts(test13) == true ? passed++ : failed++;
    unionDFA.accepts(test14) == false ? passed++ : failed++;
    unionDFA.accepts(test15) == true ? passed++ : failed++;
    unionDFA.accepts(test16) == true ? passed++ : failed++;
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
            return c == _o ? 'O' : '!';
          case 'O':
            return c == _n ? 'N' : '!';
          case 'N':
            return 'N';
          default:
            return c == _j ? 'J' : '!';
        }
      },
      [](char qi) { return qi == 'N'; });

  DFA<char> acceptWithJay(
      [](char qi) { return qi == '!' || qi == 'J' || qi == 'A' || qi == 'Y'; },
      '!',
      [](char qi, Character c) {
        switch (qi) {
          case 'J':
            return c == _a ? 'A' : '!';
          case 'A':
            return c == _y ? 'Y' : '!';
          case 'Y':
            return 'Y';
          default:
            return c == _j ? 'J' : '!';
        }
      },
      [](char qi) { return qi == 'Y'; });
  String jason(alphabet);
  {
    jason.add(_j);
    jason.add(_a);
    jason.add(_s);
    jason.add(_o);
    jason.add(_n);
  }
  String jay(alphabet);
  {
    jay.add(_j);
    jay.add(_a);
    jay.add(_y);
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

  String jayjason(alphabet);
  {
    jayjason.add(_j);
    jayjason.add(_a);
    jayjason.add(_y);
    jayjason.add(_j);
    jayjason.add(_a);
    jayjason.add(_s);
    jayjason.add(_o);
    jayjason.add(_n);
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

  DFA<pair<char, char>> unionDFA2 = union_dfa(acceptWithJason, acceptWithJay);

  {
    unionDFA2.accepts(jason) == true ? passed++ : failed++;
    unionDFA2.accepts(jay) == true ? passed++ : failed++;
    unionDFA2.accepts(jasonkiesling) == true ? passed++ : failed++;
    unionDFA2.accepts(jayjason) == true ? passed++ : failed++;
    unionDFA2.accepts(jsonkiesling) == false ? passed++ : failed++;
  }

  if (failed != 0) {
    cout << "Failed " << failed << " DFA inverse" << endl;
  }
  return failed == 0;
}

template <typename T1, typename T2>
DFA<pair<T1, T2>> union_dfa(DFA<T1> dfa1, DFA<T2> dfa2) {
  function<bool(pair<T1, T2>)> Q = [dfa1, dfa2](pair<T1, T2> qi) {
    return dfa1.Q(qi.first) || dfa2.Q(qi.second);
  };
  pair<T1, T2> q0(dfa1.q0, dfa2.q0);
  function<pair<T1, T2>(pair<T1, T2>, Character)> Delta =
      [dfa1, dfa2](pair<T1, T2> qi, Character c) {
        T1 qi_1 = dfa1.Delta(qi.first, c);
        T2 qi_2 = dfa2.Delta(qi.second, c);
        pair<T1, T2> returnPair(qi_1, qi_2);
        return returnPair;
      };
  function<bool(pair<T1, T2>)> F = [dfa1, dfa2](pair<T1, T2> qi) {
    return dfa1.F(qi.first) || dfa2.F(qi.second);
  };
  DFA<pair<T1, T2>> returnDFA(Q, q0, Delta, F);
  return returnDFA;
}

bool test_intersect_dfa() {
  int failed = 0;
  int passed = 0;

  DFA<int> acceptEvenNumbers([](int qi) { return qi == 0 || qi == 1; }, 0,
                             [](int qi, Character c) {
                               if (c == char1) {
                                 return 1;
                               } else {
                                 return 0;
                               }
                             },
                             [](int qi) { return qi == 0; });

  DFA<int> acceptEvenLength([](int qi) { return qi == 0 || qi == 1; }, 0,
                            [](int qi, Character c) {
                              if (qi == 0) {
                                return 1;
                              } else {
                                return 0;
                              }
                            },
                            [](int qi) { return qi == 0; });

  DFA<pair<int, int>> intersectDFA =
      intersect_dfa(acceptEvenNumbers, acceptEvenLength);

  {
    intersectDFA.accepts(epsilon) == true ? passed++ : failed++;
    intersectDFA.accepts(test1) == false ? passed++ : failed++;
    intersectDFA.accepts(test2) == false ? passed++ : failed++;
    intersectDFA.accepts(test3) == true ? passed++ : failed++;
    intersectDFA.accepts(test4) == false ? passed++ : failed++;
    intersectDFA.accepts(test5) == true ? passed++ : failed++;
    intersectDFA.accepts(test6) == false ? passed++ : failed++;
    intersectDFA.accepts(test7) == false ? passed++ : failed++;
    intersectDFA.accepts(test8) == false ? passed++ : failed++;
    intersectDFA.accepts(test9) == false ? passed++ : failed++;
    intersectDFA.accepts(test10) == false ? passed++ : failed++;
    intersectDFA.accepts(test11) == false ? passed++ : failed++;
    intersectDFA.accepts(test12) == false ? passed++ : failed++;
    intersectDFA.accepts(test13) == false ? passed++ : failed++;
    intersectDFA.accepts(test14) == false ? passed++ : failed++;
    intersectDFA.accepts(test15) == true ? passed++ : failed++;
    intersectDFA.accepts(test16) == false ? passed++ : failed++;
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
            return c == _o ? 'O' : '!';
          case 'O':
            return c == _n ? 'N' : '!';
          case 'N':
            return 'N';
          default:
            return c == _j ? 'J' : '!';
        }
      },
      [](char qi) { return qi == 'N'; });

  DFA<char> acceptWithJay(
      [](char qi) { return qi == '!' || qi == 'J' || qi == 'A' || qi == 'Y'; },
      '!',
      [](char qi, Character c) {
        switch (qi) {
          case 'J':
            return c == _a ? 'A' : '!';
          case 'A':
            return c == _y ? 'Y' : '!';
          case 'Y':
            return 'Y';
          default:
            return c == _j ? 'J' : '!';
        }
      },
      [](char qi) { return qi == 'Y'; });
  String jason(alphabet);
  {
    jason.add(_j);
    jason.add(_a);
    jason.add(_s);
    jason.add(_o);
    jason.add(_n);
  }
  String jay(alphabet);
  {
    jay.add(_j);
    jay.add(_a);
    jay.add(_y);
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

  String jayjason(alphabet);
  {
    jayjason.add(_j);
    jayjason.add(_a);
    jayjason.add(_y);
    jayjason.add(_j);
    jayjason.add(_a);
    jayjason.add(_s);
    jayjason.add(_o);
    jayjason.add(_n);
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

  DFA<pair<char, char>> intersectDFA2 =
      intersect_dfa(acceptWithJason, acceptWithJay);

  {
    intersectDFA2.accepts(jason) == false ? passed++ : failed++;
    intersectDFA2.accepts(jay) == false ? passed++ : failed++;
    intersectDFA2.accepts(jasonkiesling) == false ? passed++ : failed++;
    intersectDFA2.accepts(jayjason) == true ? passed++ : failed++;
    intersectDFA2.accepts(jsonkiesling) == false ? passed++ : failed++;
  }

  if (failed != 0) {
    cout << "Failed " << failed << " DFA inverse" << endl;
  }
  return failed == 0;
}

template <typename T1, typename T2>
DFA<pair<T1, T2>> intersect_dfa(DFA<T1> dfa1, DFA<T2> dfa2) {
  function<bool(pair<T1, T2>)> Q = [dfa1, dfa2](pair<T1, T2> qi) {
    return dfa1.Q(qi.first) || dfa2.Q(qi.second);
  };
  pair<T1, T2> q0(dfa1.q0, dfa2.q0);
  function<pair<T1, T2>(pair<T1, T2>, Character)> Delta =
      [dfa1, dfa2](pair<T1, T2> qi, Character c) {
        T1 qi_1 = dfa1.Delta(qi.first, c);
        T2 qi_2 = dfa2.Delta(qi.second, c);
        pair<T1, T2> returnPair(qi_1, qi_2);
        return returnPair;
      };
  function<bool(pair<T1, T2>)> F = [dfa1, dfa2](pair<T1, T2> qi) {
    return dfa1.F(qi.first) && dfa2.F(qi.second);
  };
  DFA<pair<T1, T2>> returnDFA(Q, q0, Delta, F);
  return returnDFA;
}

bool test_subset_dfa() {
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

  DFA<int> acceptEvenLength([](int qi) { return qi == 0 || qi == 1; }, 0,
                            [](int qi, Character c) {
                              if (qi == 0) {
                                return 1;
                              } else {
                                return 0;
                              }
                            },
                            [](int qi) { return qi == 0; });

  DFA<int> acceptIfHasZero([](int qi) { return qi == 0 || qi == 1; }, 0,
                           [](int qi, Character c) {
                             if (qi == 1) {
                               return 1;
                             } else if (c == char0) {
                               return 1;
                             } else {
                               return 0;
                             }
                           },
                           [](int qi) { return qi == 1; });

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
            return c == _o ? 'O' : '!';
          case 'O':
            return c == _n ? 'N' : '!';
          case 'N':
            return 'N';
          default:
            return c == _j ? 'J' : '!';
        }
      },
      [](char qi) { return qi == 'N'; });

  DFA<char> acceptWithJ([](char qi) { return qi == '!' || qi == 'J'; }, '!',
                        [](char qi, Character c) {
                          switch (qi) {
                            case 'J':
                              return 'J';
                            default:
                              return c == _j ? 'J' : '!';
                          }
                        },
                        [](char qi) { return qi == 'J'; });

  subset_dfa(acceptEvenNumbers, acceptEvenLength, binaryAlpha) == false
      ? passed++
      : failed++;

  subset_dfa(acceptIfHasZero, acceptEvenLength, binaryAlpha) == false
      ? passed++
      : failed++;

  subset_dfa(acceptWithJason, acceptWithJ, alphabet) == true ? passed++
                                                             : failed++;

  if (failed != 0) {
    cout << "Failed " << failed << " DFA subset tests" << endl;
  }
  return failed == 0;
}

template <typename T1, typename T2>
bool subset_dfa(DFA<T1> x, DFA<T2> y, Alphabet alpha) {
  DFA<T2> inverseY = inverse_dfa(y);
  DFA<pair<T1, T2>> intersectDFA = intersect_dfa(x, inverseY);
  String result = find_string(intersectDFA, alpha);
  if (result.hasFailed()) {
    return true;
  }
  return false;
}

bool test_equal_dfa() {
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

  DFA<int> acceptEvenLength([](int qi) { return qi == 0 || qi == 1; }, 0,
                            [](int qi, Character c) {
                              if (qi == 0) {
                                return 1;
                              } else {
                                return 0;
                              }
                            },
                            [](int qi) { return qi == 0; });

  DFA<int> acceptIfHasZero([](int qi) { return qi == 0 || qi == 1; }, 0,
                           [](int qi, Character c) {
                             if (qi == 1) {
                               return 1;
                             } else if (c == char0) {
                               return 1;
                             } else {
                               return 0;
                             }
                           },
                           [](int qi) { return qi == 1; });

  DFA<int> acceptIfHasZero2([](int qi) { return qi == 0 || qi == 1; }, 0,
                            [](int qi, Character c) {
                              if (qi == 1) {
                                return 1;
                              } else if (c == char0) {
                                return 1;
                              } else {
                                return 0;
                              }
                            },
                            [](int qi) { return qi == 1; });

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
            return c == _o ? 'O' : '!';
          case 'O':
            return c == _n ? 'N' : '!';
          case 'N':
            return 'N';
          default:
            return c == _j ? 'J' : '!';
        }
      },
      [](char qi) { return qi == 'N'; });

  DFA<char> acceptWithJ([](char qi) { return qi == '!' || qi == 'J'; }, '!',
                        [](char qi, Character c) {
                          switch (qi) {
                            case 'J':
                              return 'J';
                            default:
                              return c == _j ? 'J' : '!';
                          }
                        },
                        [](char qi) { return qi == 'J'; });

  DFA<char> acceptWithJ2([](char qi) { return qi == '!' || qi == 'J'; }, '!',
                         [](char qi, Character c) {
                           switch (qi) {
                             case 'J':
                               return 'J';
                             default:
                               return c == _j ? 'J' : '!';
                           }
                         },
                         [](char qi) { return qi == 'J'; });

  equal_dfa(acceptEvenNumbers, acceptEvenLength, binaryAlpha) == false
      ? passed++
      : failed++;

  equal_dfa(acceptIfHasZero, acceptEvenLength, binaryAlpha) == false ? passed++
                                                                     : failed++;

  equal_dfa(acceptWithJason, acceptWithJ, alphabet) == false ? passed++
                                                             : failed++;

  equal_dfa(acceptWithJ, acceptWithJ2, alphabet) == true ? passed++ : failed++;

  equal_dfa(acceptIfHasZero, acceptIfHasZero2, binaryAlpha) == true ? passed++
                                                                    : failed++;

  if (failed != 0) {
    cout << "Failed " << failed << " DFA equality tests" << endl;
  }
  return failed == 0;
}

template <typename T1, typename T2>
bool equal_dfa(DFA<T1> x, DFA<T2> y, Alphabet alpha) {
  DFA<T2> inverseY = inverse_dfa(y);
  DFA<pair<T1, T2>> intersectDFA1 = intersect_dfa(x, inverseY);

  DFA<T1> inverseX = inverse_dfa(x);
  DFA<pair<T2, T1>> intersectDFA2 = intersect_dfa(y, inverseX);

  String result1 = find_string(intersectDFA1, alpha);
  String result2 = find_string(intersectDFA2, alpha);
  if (result1.hasFailed() && result2.hasFailed()) {
    return true;
  }
  return false;
}

bool test_manual_equal_dfa() {
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

  DFA<int> acceptOddNumbers([](int qi) { return qi == 0 || qi == 1; }, 0,
                            [](int qi, Character c) {
                              if (c == char1) {
                                return 1;
                              } else {
                                return 0;
                              }
                            },
                            [](int qi) { return qi == 1; });

  DFA<int> acceptEvenInverse = inverse_dfa(acceptEvenNumbers);

  equal_dfa(acceptEvenInverse, acceptOddNumbers, binaryAlpha) == true
      ? passed++
      : failed++;

  if (failed != 0) {
    cout << "Failed " << failed << " DFA manual equality tests" << endl;
  }
  return failed == 0;
}

bool test_nfa() {
  int passed = 0;
  int failed = 0;

  function<bool(Character)> Q = [](Character state) {
    return state == _a || state == _b || state == _c || state == _d;
  };

  function<vector<Character>(Character, Character)> delta = [](Character state,
                                                               Character next) {
    vector<Character> d;
    if (next == _epsilon) return d;
    if (state == _a) {
      d.push_back(_a);
      if (next == 1) {
        d.push_back(_b);
      }
    } else if (state == _b) {
      d.push_back(_c);
    } else if (state == _c) {
      d.push_back(_d);
    }
    return d;
  };

  function<bool(Character)> F = [](Character state) { return state == _d; };

  NFA<Character> thirdFromEndIsOne(Q, _a, delta, F);

  function<bool(Character)> eQ = [](Character state) {
    return state == _a || state == _b;
  };

  function<vector<Character>(Character, Character)> eDelta =
      [](Character state, Character next) {
        vector<Character> d;
        if (state == _a && next == -1) {
          d.push_back(_b);
          return d;
        }
        d.push_back(_a);
        return d;
      };

  function<bool(Character)> eF = [](Character state) { return state == _d; };

  NFA<Character> passWithEpsilon(eQ, _a, eDelta, eF);

  if (failed != 0) {
    cout << "Failed " << failed << " NFA tests" << endl;
  }
  return failed == 0;
}