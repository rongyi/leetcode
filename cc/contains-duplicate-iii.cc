// http://leetcode.com/problems/contains-duplicate-iii/description/
#include "xxx.hpp"

class Solution {
public:
  bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t) {
    set<long long> window;

    for (int i = 0; i < nums.size(); i++) {
      // index range at most k!
      if (i > k) {
        window.erase(nums[i - k - 1]);
      }
      // |x - nums[i]| <= t  ==> -t <= x - nums[i] <= t;
      auto pos = window.lower_bound((long long)nums[i] - t); // x-nums[i] >= -t ==> x >= nums[i]-t
      // x - nums[i] <= t ==> |x - nums[i]| <= t
      if (pos != window.end() && *pos - nums[i] <= t) {
        return true;
      }

      window.insert(nums[i]);
    }

    return false;
  }
};
