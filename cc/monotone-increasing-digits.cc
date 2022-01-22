// http://leetcode.com/problems/monotone-increasing-digits/description/
#include "xxx.hpp"

class Solution {
public:
  int monotoneIncreasingDigits(int num) {
    string s = to_string(num);
    string ms(s);
    const int n = s.size();
    for (int i = 0; i < n; i++) {
      // 反了
      // 这一位置9，前面那位相应减一
      for (int j = i; j >= 1 && ms[j - 1] > ms[j]; j--) {
        ms[j] = '9';
        if (ms[j - 1] == s[j - 1]) {
          ms[j - 1]--;
        }
      }
    }
    return stoi(ms);
  }
};
