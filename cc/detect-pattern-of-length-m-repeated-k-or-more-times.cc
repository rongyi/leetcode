// http://leetcode.com/problems/detect-pattern-of-length-m-repeated-k-or-more-times/description/
#include "xxx.h"

class Solution {
public:
  bool containsPattern(vector<int> &arr, int m, int k) {
    if (arr.size() < m * k) {
      return false;
    }
    int count = 0;
    // 这思路优秀
    for (int i = 0; i < arr.size() - m; ++i) {
      if (arr[i] != arr[i + m]) {
        count = 0;
      }
      count += (arr[i] == arr[i + m]);
      if (count == (k - 1) * m) {
        return true;
      }
    }
    return false;
  }
};
