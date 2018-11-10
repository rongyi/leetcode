// http://leetcode.com/problems/expression-add-operators/description/
#include "simpleone.h"

class Solution {
public:
  // https://leetcode.com/problems/expression-add-operators/discuss/71898/17-lines-solution-dfs-(C%2B%2B)
  vector<string> addOperators(string nums, int target) {
    vector<string> ret;

    dfs(nums, target, 0, 0, 0, "", ret);

    return ret;
  }
  void dfs(string &s, const int target, int pos, long cur_sum, long last_stage,
           string cur_ops, vector<string> &ret) {
    if (pos == s.size() && cur_sum == target) {
      ret.push_back(cur_ops);
      return;
    }
    for (int i = 1; i <= s.size() - pos; i++) {
      string tmp = s.substr(pos, i);
      if (i > 1 && tmp[0] == '0') {
        continue;
      }
      long n = stol(tmp);
      if (pos == 0) {
        dfs(s, target, i, n, n, tmp, ret);
        continue;
      }
      dfs(s, target, pos + i, cur_sum + n, n, cur_ops + "+" + tmp, ret);
      dfs(s, target, pos + i, cur_sum - n, -n, cur_ops + "-" + tmp, ret);
      // 这里的计算，我是没想出来
      // 1+2*7
      // 乘号这里 cur_sum = 3, last_stage = 2，算这个值为(3 - 2) + 2 * 7
      // 1 + 2 * 7 * 8算到第二个乘号这里
      // cur_sum = 15, last_stage = 14 ==> (15 - 14) + 14 * 8
      dfs(s, target, pos + i, cur_sum - last_stage + last_stage * n, last_stage * n, cur_ops + "*" + tmp, ret);
    }
  }
};
