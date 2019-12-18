#ifndef NFA_HPP
#define NFA_HPP

// #include <algorithm>   // std::find
#include <functional>  // std::function
// #include <iostream>    // Testing only
// #include <optional>    // stdd::nullopt
// #include <utility>     // std::pair
#include <vector>  // std::vector
#include "Alphabet.hpp"
#include "DFA.hpp"
#include "String.hpp"
using namespace std;

template <class State>
class NFA {
 public:
  function<bool(State)> Q;
  State q0;
  function<vector<State>(State, Character)> Delta;
  function<bool(State)> F;

  NFA(function<bool(State)> Q, State q0,
      function<vector<State>(State, Character)> Delta, function<bool(State)> F)
      : Q(Q), q0(q0), Delta(Delta), F(F){};

  bool oracle(vector<pair<State, Character>> trace) {
    if (trace.size() == 0) {
      return true;
    }

    for (int i = 1; i < trace.size(); i++) {
      vector<State> d = Delta(trace[i - 1].first, trace[i].second);

      typename vector<State>::iterator it;
      it = find(d.begin(), d.end(), trace[i].first);
      if (it == d.end()) {
        return false;
      }
    }
    return true;
  }
};

template <class State>
NFA<State> dfa_to_nfa(DFA<State> dfa) {
  function<State(State state, Character)> delta = [dfa](State state,
                                                        Character next) {
    vector<State> d;
    if (next != Character(-1)) {
      d.push_back(dfa.delta(next));
    }
    return d;
  };

  NFA<State> nfa(dfa.Sigma, dfa.Q, delta, dfa.q0, dfa.F);

  return nfa;
}

#endif