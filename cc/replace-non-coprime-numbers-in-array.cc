// https://leetcode.com/problems/replace-non-coprime-numbers-in-array/
#include "xxx.hpp"

class Solution {
public:
  vector<int> replaceNonCoprimes(vector<int> &nums) {
    list<long long> l(nums.begin(), nums.end());
    for (auto it = l.begin(); it != l.end(); ++it) {
      if (it != l.begin()) {
        auto i = *prev(it);
        auto j = *it;
        auto k = __gcd(i, j);
        if (k > 1) {
          l.erase(prev(it));
          *it = (i * j) / k;
          // and the for action will ++it, and point to here again
          --it;
        }
      }
    }

    return vector<int>(begin(l), end(l));
  }
};
