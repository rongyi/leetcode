// http://leetcode.com/problems/make-sum-divisible-by-p/description/
#include "xxx.hpp"

class Solution {
public:
  int minSubarray(vector<int> &nums, int p) {
    int total = 0;
    // 总的数组和余下多少，那么去掉的子数组和就应该余这么多
    for (int i = 0; i < nums.size(); ++i) {
      total = (total + nums[i]) % p;
    }
    // sum ->  index
    unordered_map<int, int> prefix_sum;
    prefix_sum[0] = -1;

    int cur_sum = 0;
    int ret = nums.size();
    for (int i = 0; i < nums.size(); ++i) {
      // 从0到这里的数组余为cur_sum
      cur_sum = (cur_sum + nums[i]) % p;
      prefix_sum[cur_sum] = i;
      // 那么我们希望中间能有一段余这么多： cur_sum -
      // total，那么去掉这一段余就符合预期的total
      int expect_delta = (cur_sum - total + p) % p;
      if (prefix_sum.count(expect_delta)) {
        ret = min(ret, i - prefix_sum[expect_delta]);
      }
    }
    if (ret == nums.size()) {
      return -1;
    }

    return ret;
  }
};
