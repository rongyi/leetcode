// https://leetcode.com/problems/closest-prime-numbers-in-range/
#include "xxx.hpp"

class Solution {
public:
  vector<int> closestPrimes(int left, int right) {
    vector<int> ps;
    // triky part, left will give you 1
    for (int i = max(left, 2); i <= right; ++i) {
      // check prime
      bool cur_prime = true;
      for (int j = 2; j * j <= i; ++j) {
        if ((i % j) == 0) {
          cur_prime = false;
          break;
        }
      }
      if (cur_prime) {
        ps.push_back(i);
      }
    }
    if (ps.size() < 2) {
      return {-1, -1};
    }
    int min_gap = numeric_limits<int>::max();
    int min_first_idx = -1;
    for (int i = 1; i < ps.size(); ++i) {
      int cur_gap = ps[i] - ps[i - 1];
      if (cur_gap < min_gap) {
        min_first_idx = i - 1;
        min_gap = cur_gap;
      }
    }

    return {ps[min_first_idx], ps[min_first_idx + 1]};
  }
};
