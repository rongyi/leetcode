// http://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/description/
#include "xxx.h"

class Solution {
public:
  // 可加可减，找到中间的来平衡其他的即可
  int minMoves2(vector<int> &nums) {
    const int n = nums.size();
    sort(nums.begin(), nums.end());
    auto mid = nums[n / 2];

    int ret = 0;
    for (auto i : nums) {
      ret += abs(i - mid);
    }
    return ret;
  }
};
