// http://leetcode.com/problems/mean-of-array-after-removing-some-elements/description/
#include "xxx.h"

class Solution {
public:
  double trimMean(vector<int> &arr) {
    sort(arr.begin(), arr.end());
    const int n = arr.size();
    double sum = 0;

    for (int i = n / 20; i < n - n / 20; ++i) {
      sum += arr[i];
    }

    return sum / (n - n / 10);
  }
};
