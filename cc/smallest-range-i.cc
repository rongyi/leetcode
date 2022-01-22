// http://leetcode.com/problems/smallest-range-i/description/
#include "xxx.hpp"

class Solution {
public:
  int smallestRangeI(vector<int> &A, int K) {
    if (A.size() < 2) {
      return 0;
    }
    int low = *min_element(A.begin(), A.end());
    int high = *max_element(A.begin(), A.end());

    auto delta = high - low;
    if (delta - 2 * K > 0) {
      return delta - 2 * K;
    }
    return 0;
  }
};
