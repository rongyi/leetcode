// https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/
#include "xxx.hpp"

class Solution {
public:
  int minimizedMaximum(int n, vector<int> &quantities) {
    // left/right are the num for each store
    int left = 1;
    int right = 1e5;
    while (left < right) {
      int mid = (left + right) / 2;
      int need_store = 0;
      for (int q : quantities) {
        need_store += (q + mid - 1) / mid;
      }
      if (need_store > n) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }
    return left;
  }
};
