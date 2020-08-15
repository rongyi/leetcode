// http://www.lintcode.com/zh-cn/problem/minimum-window-subsequence
#include "xxx.h"

class Solution {
public:
  string minWindow(string S, string T) {
    const int m = S.size();
    const int n = T.size();
    int i = 0;
    int j = 0;
    int start = -1;
    int min_len = numeric_limits<int>::max();
    while (i < m) {
      // 一直往前找到能够包含T的子串
      if (S[i] == T[j]) {
        j++;
        // 找到一个全部了，往前走
        if (j == n) {
          int current = i + 1;
          while (--j >= 0) {
            // 不相等就一直退，一直退到遇到一个与T[j]相等的，这样保证subseq 包含T最短
            // 能去掉的重复都去掉了
            while (S[i--] != T[j]) {
              ;
            }
          }
          // i也多减了
          ++i;
          // j此时为-1
          ++j;
          if (current - i < min_len) {
            min_len = current - i;
            start = i;
          }
        }
      }
      i++;
    }

    return start == -1 ? "" : S.substr(start, min_len);
  }
};
int main() {
  Solution so;
  string s{"abcdebdde"};
  string t{"bde"};
  auto ret = so.minWindow(s, t);
  cout << ret << endl;
}
