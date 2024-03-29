// http://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/description/
#include "xxx.hpp"

class Solution {
public:
  int longestSubsequence(vector<int> &arr, int difference) {
    unordered_map<int, int> count;
    int ret = 0;
    for (int i = 0; i < arr.size(); ++i) {
      // 前面有就串起来
      count[arr[i]] = 1 + count[arr[i] - difference];
      ret = max(ret, count[arr[i]]);
    }
    return ret;
  }
};
