// http://leetcode.com/problems/combination-sum/description/
#include "xxx.hpp"

class Solution {
public:
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    vector<int> cur_lst;
    vector<vector<int>> ret;

    dfs(candidates, 0, cur_lst, ret, target);

    return ret;
  }

private:
  void dfs(vector<int> &candidates, int idx, vector<int> &cur_lst,
           vector<vector<int>> &ret, int target) {
    if (target < 0) {
      return;
    }
    if (target == 0) {
      ret.push_back(cur_lst);
      return;
    }
    if (idx == candidates.size()) {
      return;
    }
    // don't take current
    dfs(candidates, idx + 1, cur_lst, ret, target);

    // take current
    cur_lst.push_back(candidates[idx]);
    dfs(candidates, idx, cur_lst, ret, target - candidates[idx]);
    cur_lst.pop_back();
  }
};

