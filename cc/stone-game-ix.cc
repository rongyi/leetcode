// https://leetcode.com/problems/stone-game-ix/
#include "xxx.hpp"
class Solution {
public:
  bool stoneGameIX(vector<int> &stones) {
    vector<int> mod(3, 0);
    int n = stones.size();
    for (int i = 0; i < n; ++i) {
      mod[stones[i] % 3]++;
    }

    // Start with any element with mod3 equal to 1 or 2 and greedily take
    // elements that do not form sum divisible by 3.
    return get(mod, n, 2) || get(mod, n, 1);
  }

private:
  bool get(vector<int> mod, int n, int k) {
    if (mod[k] < 1) {
      return false;
    }
    mod[k]--;
    int sum = k;
    // start with 1 because we have already take a num:
    // the above action
    for (int i = 1; i < n; ++i) {
      if (mod[1] && (sum + 1) % 3 != 0) {
        mod[1]--;
        sum += 1;
      } else if (mod[2] && (sum + 2) % 3 != 0) {
        mod[2]--;
        sum += 2;
      } else if (mod[0] > 0 && (sum) % 3 != 0) {
        mod[0]--;
      } else {
        // no step, alice win at odd index
        // because the start 1 index belongs to alice
        return i & 1;
      }
    }
    return false;
  }
};
