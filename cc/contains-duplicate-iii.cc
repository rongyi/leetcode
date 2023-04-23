// http://leetcode.com/problems/contains-duplicate-iii/description/
#include "xxx.hpp"

class Solution {
public:
  bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t) {
    set<long long> window;

    for (int i = 0; i < nums.size(); i++) {
      // index range at most k!
      // 0.... k - 1, k
      //              ^ still valid
      //              k, k + 1
      //                  ^ not valid
      if (i > k) {
        window.erase(nums[i - k - 1]);
      }
      // find a number which its distance between it and nums[i]
      // is smalleder than t
      // so let this value be x, then
      // |x - nums[i]| <= t  ==> -t <= x - nums[i] <= t;
      // x-nums[i] >= -t ==> x >= nums[i]-t
      // x - nums[i] <= t ==> |x - nums[i]| <= t
      auto pos = window.lower_bound((long long)nums[i] - t);
      if (pos != window.end() && *pos - nums[i] <= t) {
        return true;
      }

      window.insert(nums[i]);
    }

    return false;
  }
};
