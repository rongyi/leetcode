// http://leetcode.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted/description/
#include "xxx.hpp"
class Solution {
public:
  // 是连续的，所以看中间那块能有多短
  int findLengthOfShortestSubarray(vector<int> &arr) {
    const int n = arr.size();
    int right = n - 1;
    for (; right > 0 && arr[right - 1] <= arr[right]; --right)
      ;
    auto ret = right;
    for (int left = 0;
         // 注意右边界right
         left < right && (left == 0 || arr[left - 1] <= arr[left]); ++left) {
      // 不符合非递减条件
      while (right < n && arr[right] < arr[left]) {
        ++right;
      }
      ret = min(ret, right - left - 1);
    }

    return ret;
  }
};
