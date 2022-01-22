// http://leetcode.com/problems/reverse-pairs/description/
#include "xxx.hpp"

class Solution {
public:
  int reversePairs(vector<int> &nums) {
    return mergeSort(nums, 0, nums.size() - 1);
  }

private:
  int mergeSort(vector<int> &nums, int s, int e) {
    if (s >= e) {
      return 0;
    }
    int mid = s + (e - s) / 2;
    int cnt = mergeSort(nums, s, mid) + mergeSort(nums, mid + 1, e);
    for (int i = s, j = mid + 1; i <= mid; i++) {
      while (j <= e && nums[i] / 2.0 > nums[j]) {
        j++;
      }
      cnt += j - (mid + 1);
    }
    sort(nums.begin() + s, nums.begin() + e + 1);
    return cnt;
  }
};
