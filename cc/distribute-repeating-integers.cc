// http://leetcode.com/problems/distribute-repeating-integers/description/
#include "xxx.hpp"

class Solution {
public:
  bool canDistribute(vector<int> &nums, vector<int> &quantity) {
    // 优先满足数量高的情况
    sort(quantity.rbegin(), quantity.rend());
    ret_ = false;

    map<int, int> count;
    for (auto &num : nums) {
      count[num]++;
    }
    vector<int> occs;
    for (auto &kv : count) {
      occs.push_back(kv.second);
    }

    dfs(quantity, occs, 0);

    return ret_;
  }

private:
  void dfs(vector<int> &quantity, vector<int> &counts, int cur) {
    if (cur == quantity.size() || ret_) {
      ret_ = true;
      return;
    }
    for (int i = 0; i < counts.size(); ++i) {
      int n = counts[i];
      if (n >= quantity[cur]) {
        counts[i] -= quantity[cur];
        dfs(quantity, counts, cur + 1);
        counts[i] += quantity[cur];
      }
    }
  }

private:
  bool ret_;
};
