// http://leetcode.com/problems/maximum-69-number/description/
#include "xxx.hpp"

class Solution {
public:
  int maximum69Number(int num) {
    auto s = to_string(num);

    // find the first '6' from left to right and change
    // it to '9'
    int six_index = -1;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '6') {
        six_index = i;
        break;
      }
    }
    if (six_index != -1) {
      s[six_index] = '9';
    }

    return stoi(s);
  }
};
