// https://leetcode.com/problems/fair-distribution-of-cookies/
#include "xxx.hpp"

class Solution {
public:
  int distributeCookies(vector<int> &cookies, int k) {
    vector<int> kids(k, 0);
    ret_ = numeric_limits<int>::max();
    dfs(cookies, kids, 0);

    return ret_;
  }
private:
  void dfs(vector<int> &cookies, vector<int> kids, int cur_idx) {
    if (cur_idx == cookies.size()) {
      ret_ = min(ret_, *max_element(kids.begin(), kids.end()));
      return;
    }
    for (int i = 0; i < kids.size(); ++i) {
      kids[i] += cookies[cur_idx];
      dfs(cookies, kids, cur_idx + 1);
      // don't give current candy to kids i
      kids[i] -= cookies[cur_idx];
      if (kids[i] == 0) {
        break;
      }
    }
  }

private:
  int ret_;
};
