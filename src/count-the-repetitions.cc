// http://leetcode.com/problems/count-the-repetitions/description/
#include "xxx.h"

class Solution {
public:
  // https://leetcode.com/problems/count-the-repetitions/discuss/119679/brutal-force-%2B-optimization-easy-understanding-c%2B%2B
  int getMaxRepetitions(string s1, int n1, string s2, int n2) {
    // s2中找到一个不存在于s1中的字符，那么怎么也凑不起来
    for (auto c : s2) {
      if (s1.find(c) == string::npos) {
        return 0;
      }
    }

    const int s1len = s1.size();
    const int s2len = s2.size();
    int p1 = 0;
    int p2 = 0;
    int mark = 0;

    while (p1 < s1len * n1) {
      char c = s2[p2 % s2len];
      // 找到相等的第一个字符
      while (s1[p1 % s1len] != c && p1 < s1len * n1) {
        p1++;
      }
      // 然后一起进步，检测下一个字符
      p2++;
      p1++;

      // 完整匹配一轮s2
      if (p2 % s2.length() == 0) {
        // 第一次匹配OK的时候记录下此时p1中的位置
        if (p2 == s2len) {
          mark = p1;
        } else if (p1 % s1len == mark % s1len) {
          // p1又走到相同的相对位置了，说明此时产生了重复的规律
          // p1 - mark是这段重复规律的长度
          // s1.length() * n1是总长， 减去已经走掉的 p1
          int round = (s1len * n1 - p1) / (p1 - mark);
          //  直接飞过去
          p1 += round * (p1 - mark);
          // 生成mark那一轮，也即第一轮要减掉
          p2 += round * (p2 - s2len);
        }
      }
    }

    // 如果s2在S1中重复了R次，那么S2(s2重复n2次构成)则肯定重复了 R / n2 次。
    return p2 / s2len / n2;
  }
};

int main() {
  Solution so;
  auto ret = so.getMaxRepetitions("abab", 5, "aabb", 1);
  cout << ret << endl;
}
