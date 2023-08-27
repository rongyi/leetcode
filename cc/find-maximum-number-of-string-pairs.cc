// https://leetcode.com/problems/find-maximum-number-of-string-pairs/
#include "xxx.hpp"

class Solution {
public:
  int maximumNumberOfStringPairs(vector<string> &words) {
    int sz = words.size();
    int ret = 0;
    for (int i = 0; i < sz; i++) {
      for (int j = i + 1; j < sz; j++) {
        string r = words[j];
        reverse(r.begin(), r.end());
        if (words[i] == r) {
          ret++;
        }
      }
    }
    return ret;
  }
};
