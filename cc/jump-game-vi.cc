// http://leetcode.com/problems/jump-game-vi/description/
#include "xxx.h"

class Solution {
public:
  int maxResult(vector<int> &nums, int k) {
    // the first index
    deque<int> dq{0};
    for (int i = 1; i < nums.size(); ++i) {
      // 保证在k step以内
      if (dq.front() + k < i) {
        dq.pop_front();
      }
      nums[i] += nums[dq.front()];
      // 保证dq里面的index上的nums[i]是非递减的
      while (!dq.empty() && nums[dq.back()] <= nums[i]) {
        dq.pop_back();
      }
      dq.push_back(i);
    }

    return nums.back();
  }
};

int main() {
  Solution so;
  vector<int> input{1, -1, 2};
  cout << so.maxResult(input, 2) << endl;
}
