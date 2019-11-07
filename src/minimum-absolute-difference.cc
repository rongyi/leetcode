// http://leetcode.com/problems/minimum-absolute-difference/description/
#include "xxx.h"

class Solution {
public:
  vector<vector<int>> minimumAbsDifference(vector<int> &arr) {
    sort(arr.begin(), arr.end());
    int min_abs = numeric_limits<int>::max();
    for (int i = 0; i < arr.size() - 1; ++i) {
      min_abs = min(min_abs, abs(arr[i + 1] - arr[i]));
    }
    vector<vector<int>> ret;
    for (int i = 0; i < arr.size() - 1; ++i) {
      if (arr[i + 1] - arr[i] == min_abs) {
        ret.push_back({arr[i], arr[i + 1]});
      }
    }
    return ret;
  }
};
