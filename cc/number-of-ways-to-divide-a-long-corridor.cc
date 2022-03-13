// https://leetcode.com/problems/number-of-ways-to-divide-a-long-corridor/
#include "xxx.hpp"

class Solution {
public:
  // https://leetcode.com/problems/number-of-ways-to-divide-a-long-corridor/discuss/1709704/Greedy-Solution-or-C%2B%2B
  int numberOfWays(string corridor) {
    using ll = long long;
    const int mod = 1e9 + 7;
    ll seat_count = accumulate(corridor.begin(), corridor.end(), 0ll,
                               [](int acc, char &cur) {
                                 if (cur == 'S') {
                                   acc += 1;
                                 }
                                 return acc;
                               });
    // seat_count must be even(2 unit devide)
    if (seat_count % 2 || seat_count == 0) {
      return 0;
    }

    int cur_count = 0;
    int prev_end = -1;
    ll ret = 1;

    for (int i = 0; i < corridor.size(); ++i) {
      if (corridor[i] == 'S') {
        cur_count += 1;
        // count seat group as 2
        if (cur_count == 2) {
          cur_count = 0;
          prev_end = i;
        } else {
          if (prev_end != -1) {
            // the gap is (i - prev_end - 1)
            // what we need is gap + 1
            ret *= (i - prev_end);
            ret %= mod;
          }
        }
      }
    }

    return ret % mod;
  }
};
