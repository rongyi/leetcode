// http://leetcode.com/problems/longer-contiguous-segments-of-ones-than-zeros/description/
#include "xxx.h"

class Solution {
public:
  bool checkZeroOnes(string s) {
    int max_zero = 0;
    int max_one = 0;
    int sz = s.size();

    for (int i = 0; i < sz;) {
      if (s[i] == '0') {
        int j = i + 1;
        while (j < sz && s[j] == '0') {
          j++;
        }
        max_zero = max(max_zero, j - i);
        i = j;
      } else {
        int j = i + 1;
        while (j < sz && s[j] == '1') {
          j++;
        }
        max_one = max(max_one, j - i);
        i = j;
      }
    }

    return max_one > max_zero;
  }
};
