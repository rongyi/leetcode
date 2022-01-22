// http://leetcode.com/problems/split-array-largest-sum/description/
#include "xxx.hpp"

class Solution {
public:
  // 思路：
  // 调整max，这个max有个区间，即[min(nums), sum(nums)]
  // 在逐渐调整过程中看用m - 1 刀切下去是否满足条件，能满足
  // 就再往下压一直压到第一个满足的即可
  int splitArray(vector<int> &nums, int m) {
    // 切最多的刀，max值最小的即为数组中最大的那个，比它小就怎么切都不对了
    int left = *max_element(nums.begin(), nums.end());
    // 切最小的刀： 0刀，整个数组是一块
    int right = accumulate(nums.begin(), nums.end(), 0ll);

    while (left < right) {
      auto mid = left + (right - left) / 2;
      if (canSplit(nums, m - 1, mid)) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }

    return left;
  }

private:
  // 下手cuts刀之后把数组切割为 cuts + 1块
  // 尽可能在满足一块之和 <= max这种情况。
  // 这样算下来的刀数就是最少了，看看这种情况是否满足？
  // 如果发现单独一个元素的都比max还大，那完了，切最多的刀留最小的块都不满足
  bool canSplit(vector<int> &nums, int cuts, long long max) {
    int acc = 0;
    for (auto num : nums) {
      if (num > max) {
        return false;
      } else if (acc + num <= max) {
        acc += num;
      } else {
        --cuts;
        acc = num;
        if (cuts < 0) {
          return false;
        }
      }
    }

    return true;
  }
};
