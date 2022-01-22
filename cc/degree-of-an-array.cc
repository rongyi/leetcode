// http://leetcode.com/problems/degree-of-an-array/description/
#include "xxx.hpp"

class Solution {
public:
  int findShortestSubArray(vector<int> &nums) {
    unordered_map<int, int> count;
    int max_count = 0;
    for (auto num : nums) {
      count[num]++;
      max_count = max(max_count, count[num]);
    }
    vector<int> max_freqs;
    for (auto kv : count) {
      if (kv.second == max_count) {
        max_freqs.push_back(kv.first);
      }
    }
    int ret = nums.size();
    for (auto num : max_freqs) {
      int cur_start = -1;
      int cur_end = -1;
      for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == num) {
          if (cur_start == -1) {
            cur_start = i;
          }
          cur_end = i;
        }
      }
      ret = min(ret, (cur_end - cur_start + 1));
    }
    return ret;
  }
};
