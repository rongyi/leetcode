// https://leetcode.com/problems/max-chunks-to-make-sorted-ii/description/
#include "one.h"
class Solution {
public:
  int maxChunksToSorted(vector<int> &arr) {
    const int n = arr.size();
    // one total chunk
    int ret = 1;
    vector<int> max_till_cur = arr;
    vector<int> min_after_cur = arr;
    for (int i = 1; i < n; ++i) {
      max_till_cur[i] = max(arr[i], max_till_cur[i - 1]);
    }
    for (int i = n - 2; i >= 0; --i) {
      min_after_cur[i] = min(arr[i], min_after_cur[i + 1]);
    }
    for (int i = 0; i < n - 1; ++i) {
      if (max_till_cur[i] <= min_after_cur[i + 1]) {
        ++ret;
      }
    }
    return ret;
  }
};
