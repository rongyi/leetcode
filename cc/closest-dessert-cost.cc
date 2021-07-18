// http://leetcode.com/problems/closest-dessert-cost/description/
#include "xxx.h"

class Solution {
public:
  int closestCost(vector<int> &baseCosts, vector<int> &toppingCosts,
                  int target) {
    int ret = 0;
    target_ = target;
    for (auto &b : baseCosts) {
      auto cur = dfs(b, toppingCosts, 0);
      ret = closest(ret, cur);
    }

    return ret;
  }

private:
  int dfs(int sum, vector<int> &ts, int tidx) {
    if (tidx >= ts.size()) {
      return sum;
    }
    // 不加
    auto a = dfs(sum, ts, tidx + 1);
    // 加一个
    auto b = dfs(sum + ts[tidx], ts, tidx + 1);
    // 加两个
    auto c = dfs(sum + ts[tidx] * 2, ts, tidx + 1);

    return closest(closest(a, b), c);
  }
  int closest(int l, int r) {
    if (l == 0) {
      return r;
    }
    if (r == 0) {
      return l;
    }
    if (abs(target_ - l) == abs(target_ - r)) {
      return l < r ? l : r;
    }
    return abs(target_ - l) < abs(target_ - r) ? l : r;
  }

private:
  int target_;
};

int main() {
  vector<int> bc{2, 3};
  vector<int> tc{4, 5, 100};
  Solution so;
  so.closestCost(bc, tc, 18);
}
