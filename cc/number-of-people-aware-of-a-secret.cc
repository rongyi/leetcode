// https://leetcode.com/problems/number-of-people-aware-of-a-secret/
#include "xxx.hpp"

class Solution {
public:
  // I have no idea! shit
  int peopleAwareOfSecret(int n, int delay, int forget) {
    long long sharing = 0;
    long long mod = 1e9 + 7;
    deque<int> dl{1};
    deque<int> fg{1};
    while (--n > 0) {
      if (dl.size() >= delay) {
        sharing = (sharing + dl.front()) % mod;
        dl.pop_front();
      }
      if (fg.size() >= forget) {
        sharing = (sharing - fg.front() + mod) % mod;
        fg.pop_front();
      }
      dl.push_back(sharing);
      fg.push_back(sharing);
    }

    return accumulate(begin(fg), end(fg), 0ll) % mod;
  }
};
