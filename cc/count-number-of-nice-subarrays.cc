// http://leetcode.com/problems/count-number-of-nice-subarrays/description/
#include "xxx.h"

class Solution {
public:
  // https://leetcode.com/problems/count-number-of-nice-subarrays/discuss/419545/JavaC%2B%2B-with-picture-deque
  int numberOfSubarrays(vector<int> &nums, int k) {
    deque<int> deq = {-1};
    int ret = 0;
    for (auto i = 0; i < nums.size(); ++i) {
      if (nums[i] % 2) {
        deq.push_back(i);
      }
      if (deq.size() > k + 1) {
        deq.pop_front();
      }
      if (deq.size() == k + 1) {
        // 意思就是从满足k个奇数开始，包含最后一个奇数，
        // 前面有多少个偶数，这个间隔表示偶数的个数，就加多少子数组
        // 而且后面遇到偶数还会这么加上去，妙的一逼
        ret += deq[1] - deq[0];
      }
    }
    return ret;
  }
};
