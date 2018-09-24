// http://leetcode.com/problems/leetcode/first-missing-positive/description/
#include "one.h"

class Solution {
public:
  int firstMissingPositive(vector<int> &nums) {
    bucket_sort(nums);

    const int n = nums.size();
    for (int i = 0; i < n; i++) {
      if (nums[i] != (i + 1))
        return i + 1;
    }
    return n + 1;
  }

private:
  void bucket_sort(vector<int> &A) {
    const int n = A.size();
    for (int i = 0; i < n; i++) {
      while (A[i] != i + 1) {
        if (A[i] <= 0 || A[i] > n || A[i] == A[A[i] - 1])
          break;
        swap(A[i], A[A[i] - 1]);
      }
    }
  }
};
