// http://www.lintcode.com/zh-cn/problem/minimum-window-subsequence
#include "one.h"

class Solution {
public:
  string minWindow(string S, string T) {
    int m = S.size(), n = T.size(), start = -1, minLen = numeric_limits<int>::max(), i = 0, j = 0;
    while (i < m) {
      if (S[i] == T[j]) {
        if (++j == n) {
          int end = i + 1;
          while (--j >= 0) {
            while (S[i--] != T[j]) {
              ;
            }
          }
          ++i;
          ++j;
          if (end - i < minLen) {
            minLen = end - i;
            start = i;
          }
        }
      }
      ++i;
    }
    return (start != -1) ? S.substr(start, minLen) : "";
  }
};
int main() {
  Solution so;
  string s{"abcdebdde"};
  string t{"bde"};
  auto ret = so.minWindow(s, t);
  cout << ret << endl;
}
