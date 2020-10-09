// http://leetcode.com/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum/description/
#include "xxx.h"

class Solution {
public:
  int minSumOfLengths(vector<int> &arr, int target) {
    vector<int> left = minLen(arr, target);

    vector<int> rvs(arr.begin(), arr.end());
    reverse(rvs.begin(), rvs.end());

    vector<int> right = minLen(rvs, target);

    const int n = arr.size();
    int min_val = n + 1;
    for (int i = 0; i < n - 1; ++i) {
      // i + 1的在逆序中的位置
      min_val = min(min_val, left[i] + right[n - 1 - i - 1]);
    }

    return min_val == n + 1 ? -1 : min_val;
  }

private:
  vector<int> minLen(vector<int> &arr, int target) {
    const int n = arr.size();
    vector<int> presum(n + 1, 0);
    unordered_map<int, int> idx;
    vector<int> ret(n, n + 1);
    idx[0] = -1;
    for (int i = 0; i < n; ++i) {
      presum[i + 1] = presum[i] + arr[i];
      int cur = n + 1;

      if (idx.find(presum[i + 1] - target) != idx.end()) {
        cur = i - idx[presum[i + 1] - target];
      }
      idx[presum[i + 1]] = i;

      ret[i] = i == 0 ? cur : min(ret[i - 1], cur);
    }

    return ret;
  }
};
