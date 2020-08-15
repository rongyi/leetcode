// http://leetcode.com/problems/maximum-width-ramp/description/
#include "xxx.h"

class Solution {
public:
  int maxWidthRamp(vector<int> &A) {
    const int n = A.size();
    vector<int> min_lst(n, 0);
    vector<int> max_lst(n, 0);

    min_lst[0] = A[0];
    for (int i = 1; i < n; i++) {
      min_lst[i] = min(min_lst[i - 1], A[i]);
    }

    max_lst[n - 1] = A[n - 1];
    for (int i = n - 2; i >= 0; i--) {
      max_lst[i] = max(max_lst[i + 1], A[i]);
    }

    int left = 0;
    int right = 0;

    int ret = 0;
    while (right < n) {
      if (min_lst[left] <= max_lst[right]) {
        ret = max(ret, right - left);
        ++right;
      } else {
        ++left;
      }
    }

    return ret;
  }
};
