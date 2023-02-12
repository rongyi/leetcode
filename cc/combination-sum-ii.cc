// http://leetcode.com/problems/combination-sum-ii/description/
#include "xxx.hpp"

class Solution {
public:
  vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {

    vector<int> cur_lst;
    vector<vector<int>> ret;
    sort(candidates.begin(), candidates.end());

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
    for (int i = idx; i < candidates.size(); i++) {
      if (candidates[i] > target) {
        break;
      }
      if (i > idx && candidates[i] == candidates[i - 1]) {
        continue;
      }

      cur_lst.push_back(candidates[i]);
      dfs(candidates, i + 1, cur_lst, ret, target - candidates[i]);
      cur_lst.pop_back();
    }
  }
};
