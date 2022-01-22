// http://leetcode.com/problems/combination-sum-ii/description/
#include "xxx.hpp"

class Solution {
public:
  vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {

    vector<int> cur_vec;
    vector<vector<int>> ret;
    sort(candidates.begin(), candidates.end());

    dfs(ret, candidates, cur_vec, 0, target);
    return ret;
  }

private:
  void dfs(vector<vector<int>> &ret, vector<int> &candidates,
           vector<int> &cur_vec, int cur_index, int target) {
    if (target < 0) {
      return;
    } else if (target == 0) {
      ret.push_back(cur_vec);
      return;
    }

    const int n = candidates.size();
    for (int i = cur_index; i < n; i++) {
      // in case duplicate
      if (i > cur_index && candidates[i] == candidates[i - 1])
        continue;
      cur_vec.push_back(candidates[i]);
      // 和前面前面一题的差别，这里要走上去
      dfs(ret, candidates, cur_vec, i + 1, target - candidates[i]);
      cur_vec.pop_back();
    }
  }
};
