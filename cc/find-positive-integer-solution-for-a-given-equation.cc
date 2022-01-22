// http://leetcode.com/problems/find-positive-integer-solution-for-a-given-equation/description/
#include "xxx.hpp"

/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

class Solution {
public:
  // 喷的很厉害
  vector<vector<int>> findSolution(CustomFunction &customfunction, int z) {
    vector<vector<int>> ret;
    for (int i = 1; i <= 1000; ++i) {
      int lo = 1;
      int high = 1000;
      int mid = lo + (high - lo) / 2;
      while (lo < high) {
        if (customfunction.f(i, mid) == z) {
          ret.push_back({i, mid});
          break;
        } else if (customfunction.f(i, mid) > z) {
          high = mid;
        } else {
          lo = mid + 1;
        }
        mid = (high + lo) / 2;
      } // while end
    }

    return ret;
  }
};
