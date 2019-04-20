// http://leetcode.com/problems/non-decreasing-array/description/
#include "xxx.h"

class Solution {
public:
  bool checkPossibility(vector<int> &nums) {
    // 顺序检查凹变段和逆序检查凸变段。
    // 如果满足，则asc和desc中的较小值必然不大于1。

    int num_left = 0;
    int num_right = 0;
    const int n = nums.size();
    int maxsofar = numeric_limits<int>::min();
    for (int i = 0; i < n; i++) {
      if (nums[i] >= maxsofar) {
        maxsofar = nums[i];
      } else {
        num_left++;
      }
    }
    int minsofar = numeric_limits<int>::max();
    for (int i = n - 1; i >= 0; i--) {
      if (nums[i] <= minsofar) {
        minsofar = nums[i];
      } else {
        num_right++;
      }
    }
    return !(num_left > 1 && num_right > 1);
  }
};

int main() {
  Solution so;
  vector<int> input{4, 2, 1};
  so.checkPossibility(input);
}
