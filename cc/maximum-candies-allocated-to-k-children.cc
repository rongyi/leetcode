// https://leetcode.com/problems/maximum-candies-allocated-to-k-children/
#include "xxx.hpp"

class Solution {
public:
  int maximumCandies(vector<int> &candies, long long k) {
    int l = 0;
    int r = 1e7;
    while (l < r) {
      long long m = (l + r + 1) / 2;
      long long cnt = 0;
      for (int i = 0; i < candies.size() && cnt < k; ++i) {
        cnt += candies[i] / m;
      }
      if (cnt >= k) {
        l = m;
      } else {
        r = m - 1;
      }
    }

    return l;
  }
};
