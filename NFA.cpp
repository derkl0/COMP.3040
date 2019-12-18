#include "NFA.hpp"

// template <class State>
// bool NFA<State>::oracle(vector<pair<State, Character>> trace) {
//   if (trace.size() == 0) {
//     return true;
//   }

//   for (int i = 1; i < trace.size(); i++) {
//     set<State> d = delta(trace[i - 1], trace[i].second);

//     if (!(d.count(trace[i].first))) {
//       return false;
//     }
//   }
//   return true;
// }