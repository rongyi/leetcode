// https://leetcode.com/problems/find-the-divisibility-array-of-a-string/
#include "xxx.hpp"

class Solution {
public:
  vector<int> divisibilityArray(string word, int m) {
    vector<int> ret;
    int sz = word.size();
    long long prev_left = 0;
    for (int i = 0; i < sz; i++) {
      long long cur = prev_left * 10 + (word[i] - '0');
      long long cur_left = cur % m;
      if (cur_left == 0) {
        ret.push_back(1);
      } else {
        ret.push_back(0);
      }
      prev_left = cur_left;
    }

    return ret;
  }
};
