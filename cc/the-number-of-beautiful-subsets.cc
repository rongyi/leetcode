// https://leetcode.com/problems/the-number-of-beautiful-subsets/
#include "xxx.hpp"

class Solution {
public:
  int beautifulSubsets(vector<int> &nums, int k) {
    map<int, int> freq;
    // they ask non empty subset, so empty subset should be
    // eliminated
    return dfs(nums, 0, k, freq) - 1;
  }

private:
  int dfs(vector<int> &nums, int cur, int k, map<int, int> &freq) {
    if (cur == nums.size()) {
      return 1;
    }
    // not take current
    int ret = dfs(nums, cur + 1, k, freq);
    // take with condition check
    if (!freq[nums[cur] - k] && !freq[nums[cur] + k]) {
      // take current index value
      freq[nums[cur]]++;
      ret += dfs(nums, cur + 1, k, freq);
      freq[nums[cur]]--;
    }
    return ret;
  }
};
