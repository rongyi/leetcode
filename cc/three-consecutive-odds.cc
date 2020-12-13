// http://leetcode.com/problems/three-consecutive-odds/description/
#include "xxx.h"

class Solution {
public:
  bool threeConsecutiveOdds(vector<int> &arr) {
    auto odd = [](int i) -> bool { return i & 1; };
    int n = arr.size();
    for (int i = 0; i < n - 2; ++i) {
      if (odd(arr[i]) && odd(arr[i + 1]) && odd(arr[i + 2])) {
        return true;
      }
    }

    return false;
  }
};
