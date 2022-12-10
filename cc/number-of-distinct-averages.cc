// https://leetcode.com/problems/number-of-distinct-averages/
#include "xxx.hpp"

class Solution {
public:
  int distinctAverages(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    set<double> avg;
    for (int i = 0, j = nums.size() - 1; i < j; i++, --j) {
      double cur = ((double)nums[i] + nums[j] ) / 2.0;
      avg.insert(cur);
    }

    return avg.size();
  }
};
