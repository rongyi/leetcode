// http://leetcode.com/problems/count-and-say/description/
#include "xxx.hpp"

class Solution {
public:
  string countAndSay(int n) {
    string s{"1"};
    while (n-- > 1) {
      ostringstream oss;
      for (int i = 0; i < s.size();) {
        char cur = s[i];
        int j = i + 1;
        while (j < s.size() && s[j] == cur) {
          j++;
        }
        oss << (j - i) << cur;
        i = j;
      }

      s = oss.str();
    }

    return s;
  }
};
