// http://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/
#include "one.h"

class Solution {
public:
  vector<int> twoSum(vector<int> &numbers, int target) {
    const int n = numbers.size();
    int i = 0;
    int j = n - 1;
    while (i < j) {
      auto sum = numbers[i] + numbers[j];
      if (sum == target) {
        return vector<int>{i + 1, j + 1};
      } else if (sum < target) {
        i++;
      } else {
        j--;
      }
    }
    // shutup compiler
    return vector<int>{-1, -1};
  }
};
