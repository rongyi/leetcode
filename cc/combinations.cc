// http://leetcode.com/problems/combinations/description/
#include "xxx.hpp"

class Solution {
public:
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> ret;
    vector<int> cur;
    recur(n, 1, k, ret, cur);

    return ret;
  }

private:
  void recur(int n, int idx, int k, vector<vector<int>> &ret,
             vector<int> &cur) {
    if (cur.size() == k) {
      ret.push_back(cur);
      return;
    }
    if (idx > n) {
      return;
    }
    // don't pick current
    recur(n, idx + 1, k, ret, cur);

    // pick current
    cur.push_back(idx);
    recur(n, idx + 1, k, ret, cur);
    cur.pop_back();
  }
};
