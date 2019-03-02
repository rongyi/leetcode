// http://leetcode.com/problems/magical-string/description/
#include "xxx.h"

class Solution {
public:
  // 如何生成这个magical string (Kolakoski Sequence)?
  // 设 x 为s[i]上的"数字", 如果i越界, 则 x = i;
  // 如果i是奇数, 则append x 个 1
  // 如果i是偶数, 则append x 个 2
  // 最后数一共多少个1.
  // trick: s可以定义为" ", 这样index比较好看, 然后最后记得是s.begin() 到
  // s.being() + n + 1的范围内.
  int magicalString(int n) {
    string s = " ";
    for (int i = 1, x = 0; i <= n; ++i) {
      if (i >= s.size()) {
        x = i;
      } else {
        x = s[i] - '0';
      }

      if (i & 1) {
        s.append(x, '1');
      } else {
        s.append(x, '2');
      }
    }

    return count(s.begin(), s.begin() + n + 1, '1');
  }
};
