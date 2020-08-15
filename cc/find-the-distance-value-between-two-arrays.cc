// http://leetcode.com/problems/find-the-distance-value-between-two-arrays/description/
#include "xxx.h"

class Solution {
public:
  int findTheDistanceValue(vector<int> &arr1, vector<int> &arr2, int d) {
    int ret = 0;

    for (int i = 0; i < arr1.size(); ++i) {
      bool found = false;
      for (int j = 0; j < arr2.size(); ++j) {
        if (abs(arr1[i] - arr2[j]) <= d) {
          found = true;
          break;
        }
      }
      if (!found) {
        ++ret;
      }
    }

    return ret;
  }
};
