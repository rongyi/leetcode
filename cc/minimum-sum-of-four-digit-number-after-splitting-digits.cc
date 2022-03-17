// https://leetcode.com/problems/minimum-sum-of-four-digit-number-after-splitting-digits/
#include "xxx.hpp"

class Solution {
public:
  int minimumSum(int num) {
    string s = to_string(num);
    sort(begin(s), end(s));
    string s1{s[0], s[2]};
    string s2{s[1], s[3]};
    return stoi(s1) + stoi(s2);
  }
};
