// https://leetcode.com/problems/number-of-smooth-descent-periods-of-a-stock/
#include "xxx.hpp"

class Solution {
public:
  long long getDescentPeriods(vector<int> &prices) {
    int sz = prices.size();
    vector<int> cons;
    long long ret = sz;

    int cur = 1;
    for (int i = 1; i < sz; ++i) {
      if (prices[i] == prices[i - 1] - 1) {
        cur += 1;
      } else {
        if (cur > 1) {
          cons.push_back(cur);
        }
        cur = 1;
      }
    }
    if (cur > 1) {
      cons.push_back(cur);
    }

    for (auto chunk_size : cons) {
      if (chunk_size == 2) {
        ret += 1;
      } else {
        // e.g. 4 3 2 1 => chunk_size == 4
        // we get (4 3) (3 2) (2 1) (4 3 2) (3 2 1) (4 3 2 1)
        // ==> 1 + 2 + .. + n - 1
        // ==> n * (n - 1) / 2;
        ret += ((long long)chunk_size * (chunk_size - 1)) / 2;
      }
    }

    return ret;
  }
};
