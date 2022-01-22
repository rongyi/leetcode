// http://leetcode.com/problems/minimum-number-of-swaps-to-make-the-binary-string-alternating/description/
#include "xxx.hpp"

class Solution {
public:
  int minSwaps(string s) {
    int sz = s.size();
    int zero_count = 0;
    int one_count = 0;
    for (int i = 0; i < sz; ++i) {
      if (s[i] == '0') {
        zero_count++;
      } else {
        one_count++;
      }
    }
    if (abs(zero_count - one_count) > 1) {
      return -1;
    }
    // 标准的
    string s1;
    string s2;
    for (int i = 0; i < sz; ++i) {
      if (i & 1) {
        s1.push_back('0');
        s2.push_back('1');
      } else {
        s1.push_back('1');
        s2.push_back('0');
      }
    }
    int ch1 = 0;
    int ch2 = 0;
    if (zero_count == one_count) {
      for (int i = 0; i < sz; ++i) {
        if (s[i] != s1[i]) {
          ch1++;
        }
        if (s[i] != s2[i]) {
          ch2++;
        }
      }
      return min(ch1 / 2, ch2 / 2);
    }
    // s1 '1' count is bigger when in odd case
    // s2 '0' count is bigger when in odd case
    if (one_count < zero_count) {
      s1 = s2;
    }
    for (int i = 0; i < sz; ++i) {
      if (s[i] != s1[i]) {
        ch1++;
      }
    }
    return ch1 / 2;
  }
};

int main() {
  Solution so;
  so.minSwaps("100");
}
