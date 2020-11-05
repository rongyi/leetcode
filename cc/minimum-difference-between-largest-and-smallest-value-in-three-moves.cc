#include "xxx.h"

class Solution {
public:
  int minDifference(vector<int> &nums) {
    if (nums.size() <= 4) {
      return 0;
    }
    const int n = nums.size();
    sort(nums.begin(), nums.end());
    // 排好序之后，能去掉三个的值之后的插最大值就在这几个范围内
    // 1. 去掉最高三个
    // 2. 去掉最高两个，最低一个
    // 3. ...
    // 4. 去掉最高0个，最低三个
    auto min1 = min(nums[n - 4] - nums[0], nums[n - 3] - nums[1]);
    auto min2 = min(nums[n - 2] - nums[2], nums[n - 1] - nums[3]);

    return min(min1, min2);
  }
};
