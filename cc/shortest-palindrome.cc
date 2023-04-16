// http://leetcode.com/problems/shortest-palindrome/description/
#include "xxx.hpp"

class Solution {
public:
  string shortestPalindrome(string s) {
    string rev_s = s;
    reverse(rev_s.begin(), rev_s.end());
    // find palindrome start at index 0
    string l = s + "#" + rev_s;

    vector<int> p(l.size(), 0);
    for (int i = 1; i < l.size(); i++) {
      int j = p[i - 1];
      // just fallback again and again
      while (j > 0 && l[i] != l[j]) {
        j = p[j - 1];
      }
      p[i] = (j += l[i] == l[j]);
    }

    return rev_s.substr(0, s.size() - p[l.size() - 1]) + s;
  }
};
