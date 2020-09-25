// http://leetcode.com/problems/the-k-strongest-values-in-an-array/description/
#include "xxx.h"

class Solution {
public:
  vector<int> getStrongest(vector<int> &arr, int k) {
    sort(arr.begin(), arr.end());
    const int median = arr[(arr.size() - 1) / 2];

    sort(arr.begin(), arr.end(), [&median](auto &l1, auto &l2) -> bool {
      auto s1 = abs(l1 - median);
      auto s2 = abs(l2 - median);
      if (s1 == s2) {
        return l1 > l2;
      }
      return s1 > s2;
    });

    arr.erase(arr.begin() + k, arr.end());
    return arr;
  }
};
