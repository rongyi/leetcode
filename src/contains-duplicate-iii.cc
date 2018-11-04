// http://leetcode.com/problems/palindrome-linked-list/description/
#include "simpleone.h"

class Solution {
public:
  bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t) {
    set<long long> window;

    for (int i = 0; i < nums.size(); i++) {
      // index range at most k!
      if (i > k) {
        window.erase(nums[i - k - 1]);
      }
      auto pos = window.lower_bound((long long)nums[i] - t);
      if (pos != window.end() && *pos - nums[i] <= t) {
        return true;
      }

      window.insert(nums[i]);
    }

    return false;
  }
};
