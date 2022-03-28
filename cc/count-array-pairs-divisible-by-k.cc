// https://leetcode.com/problems/count-array-pairs-divisible-by-k/
#include "xxx.hpp"

class Solution {
public:
  // gcd property
  // https://leetcode.com/problems/count-array-pairs-divisible-by-k/discuss/1784721/Count-GCDs
  long long countPairs(vector<int> &nums, int k) {
    long long ret = 0;
    unordered_map<int, int> gcds;
    for (auto n : nums) {
      long long gcdi = gcd(n, k);
      for (auto &[gcdj, cnt] : gcds) {
        if ((gcdi * gcdj) % k == 0) {
          ret += cnt;
        }
      }

      ++gcds[gcdi];
    }

    return ret;
  }
};
