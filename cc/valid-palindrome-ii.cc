// http://leetcode.com/problems/valid-palindrome-ii/description/
#include "xxx.h"

class Solution {
public:
  bool validPalindrome(string s) {
    const int n = s.size();
    for (int i = 0, j = n - 1; i < j; i++, j--) {
      if (s[i] != s[j]) {
        // 1. we delete s[j]
        int di = i;
        int dj = j - 1;
        while (di < dj && s[di] == s[dj]) {
          di++;
          dj--;
        }
        bool ok1 = di >= dj;

        // 2. we delete s[i]
        di = i + 1;
        dj = j;
        while (di < dj && s[di] == s[dj]) {
          di++;
          dj--;
        }
        return ok1 || (di >= dj);
      }
    }
    return true;
  }
};
