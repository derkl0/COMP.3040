#ifndef NFA_HPP
#define NFA_HPP

// #include <algorithm>   // std::find
#include <functional>  // std::function
// #include <iostream>    // Testing only
// #include <optional>    // stdd::nullopt
// #include <utility>     // std::pair
// #include <vector>      // std::vector
#include "Alphabet.hpp"
#include "String.hpp"
using namespace std;

template <class State>
class NFA {
 public:
  function<bool(State)> Q;
  State q0;
  function<State(State, Character)> Delta;
  function<bool(State)> F;

  NFA(function<bool(State)> Q, State q0,
      function<State(State, Character)> Delta, function<bool(State)> F)
      : Q(Q), q0(q0), Delta(Delta), F(F){};
};

#endif