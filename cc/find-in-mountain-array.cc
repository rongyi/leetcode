// http://leetcode.com/problems/find-in-mountain-array/description/
#include "xxx.h"

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class MountainArray {
public:
  int get(int index);
  int length();
};

class Solution {
public:
  int findInMountainArray(int target, MountainArray &arr) {
    auto peak = 0;
    int r = arr.length() - 1;
    while (peak < r) {
      int m = (peak + r) / 2;
      if (arr.get(m) > arr.get(m + 1)) {
        r = m;
      } else {
        peak = m + 1;
      }
    }
    auto i = bsearch(arr, target, 0, peak);
    if (i == -1) {
      return bsearch(arr, target, peak + 1, arr.length() - 1, false);
    }
    return i;
  }
  int bsearch(MountainArray &arr, int t, int l, int r, bool asc = true) {
    while (l <= r) {
      int m = (l + r) / 2;
      auto val = arr.get(m);
      if (val == t) {
        return m;
      }
      if (asc == (val < t)) {
        l = m + 1;
      } else {
        r = m - 1;
      }
    }

    return -1;
  }
};
