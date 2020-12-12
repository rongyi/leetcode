// http://leetcode.com/problems/maximum-number-of-non-overlapping-subarrays-with-sum-equals-target/description/
#include "xxx.h"

class Solution {
public:
  int maxNonOverlapping(vector<int> &nums, int target) {
    unordered_map<int, int> sum_idx;
    sum_idx[0] = -1;
    int prev_right = -1;
    int cur_sum = 0;
    int ret = 0;
    for (int i = 0; i < nums.size(); ++i) {
      cur_sum += nums[i];
      // 证明从这个记录的位置 *下一个* 位置开始到当前的位置的元素的和等于target
      if (sum_idx.count(cur_sum - target)) {
        int next_left = sum_idx[cur_sum - target] + 1;
        if (next_left > prev_right) {
          ++ret;
          prev_right = i;
        }
      }

      sum_idx[cur_sum] = i;
    }
    return ret;
  }
};

int main() {
  Solution so;
  vector<int> input{-2, 6, 6, 3, 5, 4, 1, 2, 8};
  so.maxNonOverlapping(input, 10);
}
