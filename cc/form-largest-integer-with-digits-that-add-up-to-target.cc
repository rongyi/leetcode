// http://leetcode.com/problems/form-largest-integer-with-digits-that-add-up-to-target/description/
#include "xxx.h"

class Solution {
public:
  string largestNumber(vector<int> &cost, int target) {
    if (target < 0) {
      return "0";
    }
    if (target == 0) {
      return "";
    }

    if (!dp_[target].empty()) {
      return dp_[target];
    }

    dp_[target] = "0";
    // paint number i cost cost[i - 1];
    for (int i = 1; i <= 9; ++i) {
      // paint
      auto ret = largestNumber(cost, target - cost[i - 1]);
      // 从小到大排列，就算是长度一样也替换，因为数字在变大
      if (ret != "0" && ret.size() + 1 >= dp_[target].size()) {
        dp_[target] = to_string(i) + ret;
      }
    }

    return dp_[target];
  }

private:
  string dp_[5001];
};
