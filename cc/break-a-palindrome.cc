// http://leetcode.com/problems/break-a-palindrome/description/
#include "xxx.hpp"

class Solution {
public:
  string breakPalindrome(string ps) {
    const int n = ps.size();
    // one char is palindrome forever
    if (n == 1) {
      return "";
    }
    bool is_odd = (n & 1);
    int i = 0;

    for (; i < ps.size(); i++) {
      if (ps[i] != 'a') {
        // ignore center not 'a'
        if (is_odd && i == n / 2) {
          continue;
        }
        ps[i] = 'a';
        break;
      }
    }

    // means every char is 'a', change the last one to b
    if (i == ps.size()) {
      ps[ps.size() - 1] = 'b';
    }
    return ps;
  }
};
