#ifndef DFA_HPP
#define DFA_HPP

#include <algorithm>   // std::find
#include <functional>  // std::function
#include <iostream>    // Testing only
#include <optional>    // stdd::nullopt
#include <utility>     // std::pair
#include <vector>      // std::vector
#include "Alphabet.hpp"
#include "String.hpp"
using namespace std;

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
    while (i < len) {
      qi = Delta(qi, s[i]);
      v.push_back(pair<State, Character>(qi, s[i]));
      i++;
    }
    return v;
  }

  String find_string(Alphabet alpha) {
    String string(alpha);
    vector<State> seen;
    State qi = q0;
    return search_algo(seen, qi, string, alpha);
  }

 private:
  String search_algo(vector<State> seen, State qi, String string1,
                     Alphabet alpha) {
    class vector<State>::iterator it;
    it = find(seen.begin(), seen.end(), qi);

    // have I been to this state yet?
    if (it != seen.end()) {
      string1.setFail();
      return string1;
    }
    // am I at an accepting state?
    else if (F(qi)) {
      return string1;
    }

    // what's next?
    else {
      seen.push_back(qi);  // record current
      for (int i = 0; i < alpha.size(); i++) {
        String string2 = string1;
        string2.add(alpha[i]);
        State qn = Delta(qi, alpha[i]);
        String string3 = search_algo(seen, qn, string2, alpha);
        if (!string3.hasFailed()) {
          return string3;
        }
      }
    }
    string1.setFail();
    return string1;
  }
};

template <class T1, class T2>
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

template <class T1, class T2>
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

template <class T1, class T2>
bool subset_dfa(DFA<T1> x, DFA<T2> y, Alphabet alpha) {
  DFA<T2> inverseY = inverse_dfa(y);
  DFA<pair<T1, T2>> intersectDFA = intersect_dfa(x, inverseY);
  String result = find_string(intersectDFA, alpha);
  if (result.hasFailed()) {
    return true;
  }
  return false;
}

template <class T1, class T2>
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

template <class T>
String find_string(DFA<T> dfa, Alphabet alpha) {
  return dfa.find_string(alpha);
}

template <class T>
DFA<T> inverse_dfa(DFA<T> dfa) {
  function<bool(T)> Fprime = [dfa](T qi) { return !dfa.F(qi); };
  DFA<T> returnDFA(dfa.Q, dfa.q0, dfa.Delta, Fprime);
  return returnDFA;
}

template <class T>
bool is_accepted_in_dfa(DFA<T> dfa, String string) {
  return dfa.accepts(string);
}

template <class T>
vector<pair<T, Character>> accepted_states(DFA<T> dfa, String string) {
  return dfa.accepts_with_states(dfa, string);
}

static DFA<int> charDFA(Character dfaChar) {
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

#endif