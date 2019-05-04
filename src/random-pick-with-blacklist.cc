// http://leetcode.com/problems/random-pick-with-blacklist/description/
#include "xxx.h"

class Solution {
public:
  Solution(int N, vector<int> &blacklist) {
    swap(black_, blacklist);
    sort(black_.begin(), black_.end());
    for (int i = 0; i < black_.size(); i++) {
      black_[i] -= i;
    }
    distribution_ = uniform_int_distribution<int>(0, N - 1 - black_.size());
  }

  int pick() {
    auto r = distribution_(gen_);

    return r + (upper_bound(black_.begin(), black_.end(), r) - black_.begin());
  }

private:
  vector<int> black_;
  default_random_engine gen_;
  uniform_int_distribution<int> distribution_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(N, blacklist);
 * int param_1 = obj->pick();
 */
