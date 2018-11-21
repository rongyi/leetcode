// http://leetcode.com/problems/count-of-smaller-numbers-after-self/description/
#include "simpleone.h"

class Solution {
public:
  vector<int> countSmaller(vector<int> &nums) {
    const int n = nums.size();
    if (n == 0) {
      return vector<int>{};
    }
    if (n == 1) {
      return vector<int>{0};
    }

    vector<int> ret(n, 0);
    for (int i = n - 2; i >= 0; --i) {
      for (int j = i + 1; j < n; j++) {
        if (nums[i] > nums[j]) {
          if (ret[j] == 0) {
            ret[i]++;
          } else {
            ret[i] = ret[j] + 1;
            break;
          }
        }
      }
    }

    return ret;
  }
};
