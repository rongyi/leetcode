// http://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/description/
#include "xxx.h"

class Solution {
public:
  int longestSubsequence(vector<int> &arr, int difference) {
    unordered_map<int, int> count;
    int ret = 0;
    for (int i = 0; i < arr.size(); ++i) {
      count[arr[i]] = 1 + count[arr[i] - difference];
      ret = max(ret, count[arr[i]]);
    }
    return ret;
  }
};
