// http://leetcode.com/problems/sum-of-mutated-array-closest-to-target/description/
#include "xxx.hpp"

class Solution {
public:
  int findBestValue(vector<int> &arr, int target) {
    int maxnum = 0;
    int sum = 0;
    for (auto num : arr) {
      maxnum = max(maxnum, num);
      sum += num;
    }
    if (sum <= target) {
      return maxnum;
    }
    sort(arr.begin(), arr.end());

    int removed = 0;
    int lastlx = arr.size() - 1;

    while (lastlx >= 0 && target < sum + removed * arr[lastlx]) {
      removed++;
      sum -= arr[lastlx];
      lastlx--;
    }
    int v = (target - sum) / removed;
    if (abs(target - sum - removed * v) <=
        abs(target - sum - removed * (v + 1))) {
      return v;
    }

    return v + 1;
  }
};
