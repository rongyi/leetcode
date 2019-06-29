// http://leetcode.com/problems/sum-of-subarray-minimums/description/
#include "xxx.h"

class Solution {
public:
  // 这里有详细的分析过程
  // https://leetcode.com/problems/sum-of-subarray-minimums/discuss/178876/stack-solution-with-very-detailed-explanation-step-by-step
  int sumSubarrayMins(vector<int> &A) {
    stack<pair<int, int>> prev_less;
    stack<pair<int, int>> next_less;

    vector<int> left(A.size(), 0);
    vector<int> right(A.size(), 0);

    // 默认数组全部元素
    for (int i = 0; i < A.size(); i++) {
      left[i] = i + 1;
    }
    for (int i = 0; i < A.size(); i++) {
      right[i] = A.size() - i;
    }

    for (int i = 0; i < A.size(); i++) {
      while (!prev_less.empty() && prev_less.top().first > A[i]) {
        prev_less.pop();
      }
      left[i] = prev_less.empty() ? i + 1 : i - prev_less.top().second;
      prev_less.push({A[i], i});

      while (!next_less.empty() && next_less.top().first > A[i]) {
        auto x = next_less.top();
        next_less.pop();
        right[x.second] = i - x.second;
      }

      next_less.push({A[i], i});
    }

    int ret = 0;
    const int mod = pow(10, 9) + 7;
    for (int i = 0; i < A.size(); i++) {
      ret = (ret + A[i] * left[i] * right[i]) % mod;
    }

    return ret;
  }
};
