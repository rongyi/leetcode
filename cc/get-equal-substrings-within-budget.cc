// http://leetcode.com/problems/get-equal-substrings-within-budget/description/
#include "xxx.hpp"

class Solution {
public:
  int equalSubstring(string s, string t, int maxCost) {
    const int n = s.size();
    int i = 0;
    int j = 0;
    while (i < n) {
      maxCost -= abs(s[i] - t[i]);
      i++;
      if (maxCost < 0) {
        maxCost += abs(s[j] - t[j]);
        j++;
      }
    }
    return i - j;
  }
};
