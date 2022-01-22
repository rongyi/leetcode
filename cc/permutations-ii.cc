// http://www.lintcode.com/zh-cn/problem/leetcode/permutations-ii
#include "xxx.hpp"

class Solution {
public:
  vector<vector<int>> permuteUnique(vector<int> &nums) {

    vector<vector<int>> ret;
    if (nums.size() == 0) {
      return ret;
    }
    vector<int> cur;
    doPermute(nums, ret, cur, 0);

    return ret;
  }

private:
  void doPermute(vector<int> &nums, vector<vector<int>> &ret, vector<int> &cur,
                 unsigned index) {
    if (index == nums.size()) {
      ret.push_back(cur);
      return;
    }
    unordered_set<int> uniq;
    for (unsigned i = index; i < nums.size(); ++i) {
      if (uniq.find(nums[i]) == uniq.end()) {
        uniq.insert(nums[i]);

        swap(nums[index], nums[i]);
        cur.push_back(nums[index]);
        doPermute(nums, ret, cur, index + 1);
        // restore
        cur.pop_back();
        swap(nums[index], nums[i]);
      }
    }
  }
};
