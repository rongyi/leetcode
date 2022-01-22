// https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/
#include "xxx.hpp"

class Solution {
public:
  int minimumDifference(vector<int> &nums) {
    const int n = nums.size();
    int ret = 0;
    int sum = accumulate(nums.begin(), nums.end(), 0);
    const int half = n / 2;

    // prepare all the combination sum of left half
    // and right half
    vector<vector<int>> left(half + 1);
    vector<vector<int>> right(half + 1);
    for (int mask = 0; mask < (1 << half); ++mask) {
      int sz = 0;
      int l = 0;
      int r = 0;
      for (int i = 0; i < half; ++i) {
        if (mask & (1 << i)) {
          sz++;
          l += nums[i];
          r += nums[i + half];
        }
      }
      left[sz].push_back(l);
      right[sz].push_back(r);
    }

    // prepare binary search for the right part
    for (int sz = 0; sz < half + 1; ++sz) {
      sort(right[sz].begin(), right[sz].end());
    }

    // all right case and all left case
    ret = min(abs(sum - 2 * left[half][0]), abs(sum - 2 * right[half][0]));

    for (int sz = 1; sz < half; ++sz) {
      for (auto &a : left[sz]) {
        int b = (sum - 2 * a) / 2;
        int rsz = half - sz;
        auto &v = right[rsz];
        auto it = lower_bound(v.begin(), v.end(), b);
        if (it != v.end()) {
          ret = min(ret, abs(sum - 2 * (a + (*it))));
        }
        if (it != v.begin()) {
          it = prev(it);
          ret = min(ret, abs(sum - 2 * (a + (*it))));
        }
      }
    }

    return ret;
  }
};

