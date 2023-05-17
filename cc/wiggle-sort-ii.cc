// http://leetcode.com/problems/wiggle-sort-ii/description/
#include "xxx.hpp"

class Solution {
public:
  void wiggleSort(vector<int> &nums) {
    vector<int> sorted = nums;
    sort(sorted.begin(), sorted.end());
    int sz = nums.size();
    // 排序好一个一个抽取放一起
    for (int i = 0, j = (sz - 1) / 2, k = sz - 1; i < sz; i++) {
      nums[i] = (i & 1) ? sorted[k--] : sorted[j--];
    }
  }
};
