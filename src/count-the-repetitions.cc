// http://leetcode.com/problems/count-the-repetitions/description/
#include "xxx.h"

class Solution {
public:
  int getMaxRepetitions(string s1, int n1, string s2, int n2) {
    // s2中找到一个不存在于s1中的字符，那么怎么也凑不起来
    for (auto c : s2) {
      if (s1.find(c) == string::npos) {
        return 0;
      }
    }

    int p1 = 0;
    int p2 = 0;
    int mark = 0;

    while (p1 < s1.length() * n1) {
      char c = s2[p2 % s2.length()];
      // 找到相等的第一个字符
      while (s1[p1 % s1.length()] != c && p1 < s1.length() * n1) {
        p1++;
      }
      // 然后一起进步，检测下一个字符
      p2++;
      p1++;

      // 完整匹配一轮s2
      if (p2 % s2.length() == 0) {
        if (p2 == (int)s2.length()) {
          mark = p1;
        } else if (p1 % s1.length() == mark % s1.length()) {
          // p1又走到相同的相对位置了，说明此时产生了重复的规律
          // p1 - mark是这段重复规律的长度
          // s1.length() * n1是总长， 减去已经走掉的 p1
          int round = (s1.length() * n1 - p1) / (p1 - mark);
          p1 += round * (p1 - mark);
          // 生成mark那一轮，也即第一轮要减掉
          p2 += round * (p2 - s2.length());
        }
      }
    }

    return p2 / s2.length() / n2;
  }
};

int main() {
  Solution so;
  auto ret = so.getMaxRepetitions("abab", 5, "aabb", 1);
  cout << ret << endl;
}
