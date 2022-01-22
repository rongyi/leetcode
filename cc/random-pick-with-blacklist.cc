// http://leetcode.com/problems/random-pick-with-blacklist/description/
#include "xxx.hpp"

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

  // Let's call the original domain in [1..N) and reduced domain in [1..M) where M=N-|B|.
  // We need to return X in the original domain, but can only generate a number r in the reduced domain.
  // The mapping from the original domain to the reduced domain is the relation:
  // "X - {number of elements smaller than X in B} = r" // from original domain to the reduced domain

  // The line of bl[i]-=i is to map the (impossible) X into the reduced domain.
  // So, one can find how many elements smaller than r quickly. (upper_bound()-begin()), since both r and bl[i] now in the same domain.
  // Then, map r back to the original domain, by r + {skipped elements in B}
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
