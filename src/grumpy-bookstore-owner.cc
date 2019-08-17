// http://leetcode.com/problems/grumpy-bookstore-owner/description/
#include "xxx.h"

class Solution {
public:
  int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int X) {
    const int n = customers.size();
    int directly_satified = 0;
    for (int i = 0; i < n; ++i) {
      if (!grumpy[i]) {
        directly_satified += customers[i];
        customers[i] = 0;
      }
    }

    // sliding window for secret satisfied
    int cur_sum = 0;
    int secret_satisfied = 0;
    for (int i = 0; i < n; ++i) {
      cur_sum += customers[i];
      if (i >= X) {
        cur_sum -= customers[i - X];
      }
      secret_satisfied = max(secret_satisfied, cur_sum);
    }

    return directly_satified + secret_satisfied;
  }
};
