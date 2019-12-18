#ifndef NFA_HPP
#define NFA_HPP

// #include <algorithm>   // find
#include <functional>  // function
// #include <iostream>    // Testing only
// #include <optional>    // stdd::nullopt
// #include <utility>     // pair
#include <vector>  // vector
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

    for (unsigned int i = 1; i < trace.size(); i++) {
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
      d.push_back(dfa.Delta(next));
    }
    return d;
  };

  NFA<State> nfa(dfa.Sigma, dfa.Q, delta, dfa.q0, dfa.F);

  return nfa;
}

template <class State>
class TraceTree;

template <class State>
class TraceTree {
 public:
  TraceTree(State state, Character transition, bool status,
            vector<TraceTree> children)
      : state(state),
        transition(transition),
        status(status),
        children(children){};
  State state;
  Character transition;
  bool status;
  vector<TraceTree> children;
};

template <class State>
TraceTree<State> fork_help(NFA<State> nfa, String string, State qi) {
  vector<TraceTree<State>> children;

  vector<State> epsilon = nfa.Delta(qi, Character(-1));
  for (auto i = epsilon.begin(); i != epsilon.end(); i++) {
    children.push_back(fork_help(nfa, string, *i));
  }

  if (string.length() > 0) {
    Character ch = string.front();
    vector<State> next = nfa.Delta(qi, ch);

    string.pop_front();
    for (auto i = next.begin(); i != next.end(); i++) {
      children.push_back(fork_help(nfa, string, *i));
    }
    return TraceTree<State>(qi, ch, nfa.F(qi), children);
  }
  return TraceTree<State>(qi, Character(-1), nfa.F(qi), children);
}

template <class State>
TraceTree<State> forking(NFA<State> nfa, String string) {
  return fork_help(nfa, string, nfa.q0);
}

template <class State>
void printTraceTree(TraceTree<State> tree) {
  if (tree.children.size() == 0) {
    cout << "{" << tree.state << ", " << tree.transition << ", "
         << (tree.status ? "YES" : "NO") << "}";
  } else {
    cout << "{" << tree.state << ", " << tree.transition << ", "
         << (tree.status ? "YES" : "NO") << "} --> (";
    for (unsigned int i = 0; i < tree.children.size(); i++) {
      printTraceTree(tree.children[i]);
    }
    cout << ")";
  }
}

template <class State>
bool backtrack_help(NFA<State> nfa, String string, State qi) {
  vector<State> epsilon = nfa.Delta(qi, Character(-1));
  for (auto i = epsilon.begin(); i != epsilon.end(); i++) {
    if (backtrack_help(nfa, string, *i)) {
      return true;
    }
  }
  int size = string.length();
  if (size > 0) {
    Character ch = string.front();
    vector<State> next = nfa.Delta(qi, ch);
    string.pop_front();
    for (auto i = next.begin(); i != next.end(); i++) {
      if (backtrack_help(nfa, string, *i)) {
        return true;
      }
    }
  }
  if (size <= 0) {
    return nfa.F(qi);
  }
  return false;
}

template <class State>
bool backtracking(NFA<State> nfa, String string) {
  return backtrack_help(nfa, string, nfa.q0);
}

#endif