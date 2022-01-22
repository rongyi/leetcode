// http://leetcode.com/problems/arithmetic-subarrays/description/
#include "xxx.hpp"

class Solution {
public:
  vector<bool> checkArithmeticSubarrays(vector<int> &nums, vector<int> &l,
                                        vector<int> &r) {
    // 暴力可以过
    vector<bool> ret;
    for (int i = 0; i < l.size(); ++i) {
      vector<int> cur;
      copy(nums.begin() + l[i], next(nums.begin() + r[i]), back_inserter(cur));
      if (is_arithmetic(cur)) {
        ret.push_back(true);
      } else {
        ret.push_back(false);
      }
    }
    return ret;
  }

private:
  bool is_arithmetic(vector<int> &cur) {
    sort(cur.begin(), cur.end());

    auto delta = cur[1] - cur[0];

    for (int i = 1; i < cur.size(); ++i) {
      if (cur[i] - cur[i - 1] != delta) {
        return false;
      }
    }
    return true;
  }
};
