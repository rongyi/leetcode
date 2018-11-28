// http://leetcode.com/problems/wiggle-sort-ii/description/
#include "simpleone.h"

class Solution {
public:
  void wiggleSort(vector<int> &nums) {
    vector<int> sorted = nums;
    sort(sorted.begin(), sorted.end());
    const int n = nums.size();
    // 排序好一个一个抽取放一起
    for (int i = 0, j = (n - 1) / 2, k = n - 1; i < n; i++) {
      nums[i] = (i & 1) ? sorted[k--] : sorted[j--];
    }
  }
};
