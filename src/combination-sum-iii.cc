// http://leetcode.com/problems/combination-sum-iii/description/
#include "xxx.h"

class Solution {
public:
  vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> ret;
    vector<int> cur;

    dfs(k, n, 1, cur, ret);

    return ret;
  }

private:
  void dfs(int k, int n, int index, vector<int> &cur,
           vector<vector<int>> &ret) {
    if (n < 0) {
      return;
    }
    if (n == 0 && cur.size() == k) {
      ret.push_back(cur);
    }
    for (int i = index; i <= 9; i++) {
      cur.push_back(i);
      dfs(k, n - i, i + 1, cur, ret);
      cur.pop_back();
    }
  }
};
