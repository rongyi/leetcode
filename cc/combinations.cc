// http://leetcode.com/problems/combinations/description/
#include "xxx.hpp"

class Solution {
public:
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> ret;
    vector<int> cur;
    combine(ret, cur, 1, n, k);

    return ret;
  }

private:
  void combine(vector<vector<int>> &ret, vector<int> cur, int index, int n,
               int k) {
    if (cur.size() == k) {
      ret.push_back(cur);
      return;
    }

    if (index > n) {
      return;
    }
    // don't pick current node
    combine(ret, cur, index + 1, n, k);

    // pick current node
    cur.push_back(index);
    combine(ret, cur, index + 1, n, k);
  }
};
