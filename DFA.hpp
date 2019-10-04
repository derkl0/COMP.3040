#ifndef DFA_HPP
#define DFA_HPP

#include <functional>
#include "String.hpp"

template <class State>
class DFA {
 public:
  std::function<bool(State)> Q;
  State q0;
  std::function<State(State, Character)> Delta;
  std::function<bool(State)> F;

  DFA(std::function<bool(State)> Q, State q0,
      std::function<State(State, Character)> Delta,
      std::function<bool(State)> F)
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
};

#endif