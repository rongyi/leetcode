// http://leetcode.com/problems/sliding-window-maximum/description/
#include "xxx.h"

class Solution {
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    deque<int> dq;
    vector<int> ret;
    for (int i = 0; i < nums.size(); i++) {
      // 窗口大小为K，保证最大值都是在窗口K中
      if (!dq.empty() && dq.front() == i - k) {
        dq.pop_front();
      }
      // 队列里比当前准备进来的小都给老子滚蛋
      while (!dq.empty() && nums[dq.back()] < nums[i]) {
        dq.pop_back();
      }
      dq.push_back(i);

      if (i >= k - 1) {
        ret.push_back(nums[dq.front()]);
      }
    }

    return ret;
  }
};
