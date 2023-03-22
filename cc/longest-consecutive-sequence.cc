// http://leetcode.com/problems/longest-consecutive-sequence/description/
#include "xxx.hpp"

class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
    set<int> uniq(nums.begin(), nums.end());
    int ret = 0;

    for (int i = 0; i < nums.size(); i++) {
      if (uniq.count(nums[i])) {
        uniq.erase(nums[i]);
        int cur_seq = 1;
        int j = nums[i];

        while (uniq.count(--j)) {
          uniq.erase(j);
          cur_seq++;
        }

        j = nums[i];
        while (uniq.count(++j)) {
          uniq.erase(j);
          cur_seq++;
        }

        ret = max(cur_seq, ret);
      }
    }

    return ret;
  }
};
