// https://leetcode.com/problems/minimum-number-of-moves-to-make-palindrome/
#include "xxx.hpp"

// https://leetcode.com/problems/minimum-number-of-moves-to-make-palindrome/discuss/1847011/c%2B%2B-2-pointers-with-detail-proof-and-explanation
class Solution {
public:
  int minMovesToMakePalindrome(string s) {
    int l = 0;
    int r = s.size() - 1;

    int ret = 0;
    int center_odd = -1;
    while (l < r) {
      if (s[l] == s[r]) {
        l++;
        r--;
        continue;
      }
      int k = l + 1;
      for (; k < r; ++k) {
        if (s[k] == s[r]) {
          break;
        }
      }

      // not found?
      if (k == r) {
        center_odd = r;
        r--;
        continue;
      }
      for (int j = k; j > l; --j) {
        swap(s[j], s[j - 1]);
        ret++;
      }
      l++;
      r--;
    }

    if (center_odd != -1) {
      ret += (center_odd - s.size() / 2);
    }
    return ret;
  }
};
