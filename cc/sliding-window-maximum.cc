// http://leetcode.com/problems/sliding-window-maximum/description/
#include "xxx.hpp"

class Solution {
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    map<int, int> cnt;
    vector<int> ret;
    // yes, it can pass
    for (int i = 0; i < nums.size(); i++) {
      if (i >= k) {
        cnt[nums[i - k]]--;
        if (cnt[nums[i - k]] == 0) {
          cnt.erase(nums[i - k]);
        }
      }

      cnt[nums[i]]++;

      if (i >= k - 1) {
        ret.push_back(cnt.rbegin()->first);
      }
    }

    return ret;
  }
};
