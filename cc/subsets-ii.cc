// http://leetcode.com/problems/subsets-ii/description/
#include "xxx.hpp"

class Solution {
public:
  vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ret;
    vector<int> cur;
    recur(nums, 0, cur, ret);

    return ret;
  }

public:
  void recur(vector<int> &nums, int index, vector<int> &cur,
             vector<vector<int>> &ret) {
    ret.push_back(cur);
    for (int i = index; i < nums.size(); i++) {
      if (i != index && nums[i] == nums[i - 1]) {
        continue;
      }
      // take
      cur.push_back(nums[i]);

      recur(nums, i + 1, cur, ret);
      cur.pop_back();
      // not take
    }
  }
};

