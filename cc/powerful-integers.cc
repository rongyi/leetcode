// http://leetcode.com/problems/powerful-integers/description/
#include "xxx.h"

class Solution {
public:
  vector<int> powerfulIntegers(int x, int y, int bound) {
    if (x == 1 && y == 1) {
      if (bound < 2) {
        return {};
      }
      return {x + y};
    }
    if (x == 1 || y == 1) {
      int other = x == 1 ? y : x;
      vector<int> ret;
      int count = 0;
      int multi = pow(other, count);
      while (multi <= bound) {
        ret.push_back(multi + 1);
        ++count;
        multi = pow(other, count);
      }
      return ret;
    }

    unordered_set<int> nums;
    recur(x, 0, y, 0, bound, nums);

    return vector<int>(nums.begin(), nums.end());
  }
  void recur(int x, int i, int y, int j, int bound, unordered_set<int> &nums) {
    auto left = pow(x, i);
    auto right = pow(y, j);
    if (left > bound || right > bound) {
      return;
    }
    int sum = left + right;
    if (sum <= bound) {
      nums.insert(sum);
    }
    recur(x, i, y, j + 1, bound, nums);
    recur(x, i + 1, y, j, bound, nums);
  }
};
