// https://leetcode.com/problems/find-the-longest-balanced-substring-of-a-binary-string/
#include "xxx.hpp"

class Solution {
public:
  int findTheLongestBalancedSubstring(string s) {
    int sz = s.size();
    int zsz = 0;
    int osz = 0;
    int ret = 0;
    for (int i = 0; i < sz; i++) {
      if (s[i] == '0') {
        // clear for previous round
        if (i > 0 && s[i - 1] == '1') {
          ret = max(ret, min(zsz, osz) * 2);
          zsz = 0;
          osz = 0;
        }

        zsz++;
      } else {
        osz++;
      }
    }
    ret = max(ret, min(zsz, osz) * 2);

    return ret;
  }
};

int main() {
  Solution so;
  so.findTheLongestBalancedSubstring("01011");
}
