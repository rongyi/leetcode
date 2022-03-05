// https://leetcode.com/problems/recover-the-original-array/
#include "xxx.hpp"

class Solution {
public:
  vector<int> recoverArray(vector<int> &nums) {
    // try every possible k
    multiset<int> s(nums.begin(), nums.end());
    int small = *begin(s);
    for (auto it = next(begin(s)); it != end(s); ++it) {
      int k = (*it - small) / 2;
      // a possible k
      if (k > 0 && small + 2 * k == *it) {
        vector<int> ret;
        multiset<int> cp = s;
        // try all for k
        while (!cp.empty()) {
          // low == begin
          auto highit = cp.find(*begin(cp) + 2 * k);
          // not valid
          if (highit == end(cp)) {
            break;
          }
          // assume this is valid, restore the valid origin
          ret.push_back(*begin(cp) + k);

          cp.erase(begin(cp));
          cp.erase(highit);
        }
        if (cp.empty()) {
          return ret;
        }
      }
    }

    return {};
  }
};
