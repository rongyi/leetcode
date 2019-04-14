// http://leetcode.com/problems/set-mismatch/description/
#include "xxx.h"

class Solution {
public:
  vector<int> findErrorNums(vector<int> &nums) {
    const int n = nums.size();
    long long expect_sum = (1 + n) * n / 2;
    long long cur_sum = accumulate(nums.begin(), nums.end(), 0ll);

    set<int> uniq;
    int target = 0;
    for (auto num : nums) {
      if (uniq.find(num) != uniq.end()) {
        target = num;
        break;
      }
      uniq.insert(num);
    }
    cur_sum -= target;
    return {target, (int)(expect_sum - cur_sum)};
  }
};
