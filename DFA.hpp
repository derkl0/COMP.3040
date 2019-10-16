#ifndef DFA_HPP
#define DFA_HPP

#include <algorithm>   // std::find
#include <functional>  // std::function
#include <iostream>    // Testing only
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
    typename vector<State>::iterator it;
    it = find(seen.begin(), seen.end(), qi);

    if (it != seen.end()) {
      string1.pop_back();
      return string1;
    }

    else if (F(qi)) {
      return string1;
    }

    else {
      seen.push_back(qi);
      String string3(alpha);
      for (int i = 0; i < alpha.size(); i++) {
        State qn = Delta(qi, alpha[i]);
        String string2 = string1;
        string2.add(alpha[i]);
        seen.push_back(qi);
        string3 = search_algo(seen, qn, string2, alpha);
        if (accepts(string3)) {
          break;
        }
      }
      return string3;
    }
  }
};

#endif