#ifndef DFA_HPP
#define DFA_HPP

#include <functional>
#include <utility>
#include <vector>
#include "String.hpp"
using std::function;
using std::pair;
using std::vector;

template <class State>
class DFA {
 public:
  function<bool(State)> Q;
  State q0;
  function<State(State, Character)> Delta;
  function<bool(State)> F;

  DFA(function<bool(State)> Q, State q0,
      function<State(State, Character)> Delta, function<bool(State)> F)
      : Q(Q), q0(q0), Delta(Delta), F(F){};

  bool accepts(String s) {
    auto len = s.length();
    auto qi = q0;
    auto i = 0;
    while (i < len) {
      qi = Delta(qi, s[i]);
      i++;
    }
    return F(qi);
  }

  vector<pair<State, Character>> accepts_with_states(String s) {
    vector<pair<State, Character>> v;
    auto len = s.length();
    auto qi = q0;
    auto i = 0;
    // v.push_back(pair<State, Character>(qi, s[i]));
    while (i < len) {
      qi = Delta(qi, s[i]);
      v.push_back(pair<State, Character>(qi, s[i]));
      i++;
    }
    return v;
  }
};

#endif