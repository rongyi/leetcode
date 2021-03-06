// http://leetcode.com/problems/combination-sum-iii/description/
#include "xxx.h"

class Solution {
public:
  vector<vector<int>> combinationSum3(int k, int target) {
    vector<vector<int>> ret;
    vector<int> cur;

    dfs(k, target, 1, cur, ret);

    return ret;
  }

private:
  void dfs(int k, int target, int index, vector<int> &cur,
           vector<vector<int>> &ret) {
    // 加速条件
    if (target < 0 || cur.size() > k) {
      return;
    }
    if (target == 0 && cur.size() == k) {
      ret.push_back(cur);
    }
    for (int i = index; i <= 9; i++) {
      cur.push_back(i);
      dfs(k, target - i, i + 1, cur, ret);
      cur.pop_back();
    }
  }
};
