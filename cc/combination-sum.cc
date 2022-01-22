// http://leetcode.com/problems/combination-sum/description/
#include "xxx.hpp"

class Solution {
public:
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    vector<int> cur_vec;
    vector<vector<int>> ret;
    sort(candidates.begin(), candidates.end());

    dfs(ret, candidates, cur_vec, 0, target);

    // erase duplicate
    sort(ret.begin(), ret.end());
    ret.erase(unique(ret.begin(), ret.end()), ret.end());
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
      cur_vec.push_back(candidates[i]);
      // 因为可以重复取，这里index其实没有往上加，往上加的地方在for里做掉了
      dfs(ret, candidates, cur_vec, i, target - candidates[i]);
      cur_vec.pop_back();
    }
  }
};
