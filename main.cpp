#include <functional>
#include <iostream>
#include "Alphabet.hpp"
#include "Character.hpp"
#include "DFA.hpp"
#include "String.hpp"
using namespace std;

void test_lexi(Alphabet alpha);

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

  // alpha.lexi(0);
  // alpha.lexi(1);
  // alpha.lexi(2);
  // alpha.lexi(3);
  // alpha.lexi(4);
  // alpha.lexi(5);
  // alpha.lexi(6);
  // alpha.lexi(7);
  // alpha.lexi(8);
  test_lexi(alpha);

  DFA<int> ex([](int qi) { return qi == 0 || qi == 1; }, 0,
              [](int qi, Character c) {
                if (qi == 0) {
                  return 1;
                } else {
                  return 0;
                }
              },
              [](int qi) { return qi == 0; });

  String test1(alpha);
  String test2(alpha);
  test2.add(char0);
  String test3(alpha);
  test3.add(char0);
  test3.add(char0);
  String test4(alpha);
  test4.add(char1);
  test4.add(char1);
  test4.add(char0);

  cout << ex.accepts(test1) << " should be " << true << endl;
  cout << ex.accepts(test2) << " should be " << false << endl;
  cout << ex.accepts(test3) << " should be " << true << endl;
  cout << ex.accepts(test4) << " should be " << false << endl;

  cout << endl;

  DFA<int> noStrings([](int qi) { return qi == 0 || qi == 1; }, 0,
                     [](int qi, Character c) {
                       if (qi == 0) {
                         return 1;
                       } else {
                         return 0;
                       }
                     },
                     [](int qi) { return 0; });

  cout << ex.accepts(test1) << " should be " << false << endl;
  cout << ex.accepts(test2) << " should be " << false << endl;
  cout << ex.accepts(test3) << " should be " << false << endl;
  cout << ex.accepts(test4) << " should be " << false << endl;

  return 0;
}

void test_lexi(Alphabet alpha) {
  int passed = 0;
  int failed = 0;
  String test0(alpha);
  alpha.lexi(0) == test0 ? passed++ : failed++;
  String test1(alpha);
  test1.add(alpha[0]);
  alpha.lexi(1) == test1 ? passed++ : failed++;
  String test2(alpha);
  test2.add(alpha[1]);
  alpha.lexi(2) == test2 ? passed++ : failed++;
  test1.add(alpha[0]);
  alpha.lexi(3) == test1 ? passed++ : failed++;
  String test3(alpha);
  test3.add(alpha[0]);
  test3.add(alpha[1]);
  alpha.lexi(4) == test3 ? passed++ : failed++;
  String test4(alpha);
  test4.add(alpha[1]);
  test4.add(alpha[0]);
  alpha.lexi(5) == test4 ? passed++ : failed++;
  test2.add(alpha[1]);
  alpha.lexi(6) == test2 ? passed++ : failed++;
  test1.add(alpha[0]);
  alpha.lexi(7) == test1 ? passed++ : failed++;
  String test5(alpha);
  test5.add(alpha[0]);
  test5.add(alpha[0]);
  test5.add(alpha[1]);
  alpha.lexi(8) == test5 ? passed++ : failed++;
  cout << "Test Lexi: Passed: " << passed << " Failed: " << failed
       << " Total: " << passed + failed << endl;
}