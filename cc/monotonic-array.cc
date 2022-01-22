// https://leetcode.com/problems/monotonic-array/description/
#include "xxx.hpp"
class Solution {
public:
  bool isMonotonic(vector<int> &A) {
    return isIncrease(A) || isDecrease(A);
  }

private:
  bool isIncrease(vector<int> &a) {
    const int n = a.size();
    int i = 0;
    for (i = 0; i < n - 1;) {
      if (a[i + 1] >= a[i]) {
        ++i;
      } else {
        break;
      }
    }
    return i == n - 1;
  }

  bool isDecrease(vector<int> &a) {
    const int n = a.size();
    int i = 0;
    for (i = 0; i < n - 1;) {
      if (a[i + 1] <= a[i]) {
        i++;
      } else {
        break;
      }
    }
    return i == n - 1;
  }
};
