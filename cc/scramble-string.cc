// http://leetcode.com/problems/leetcode/scramble-string/description/
#include "xxx.hpp"

class Solution {
public:
  bool isScramble(string s1, string s2) {
    // 前面这些算剪枝
    if (s1.size() != s2.size())
      return false;

    if (s1 == s2)
      return true;

    auto s1cp = s1;
    auto s2cp = s2;
    std::sort(s1cp.begin(), s1cp.end());
    std::sort(s2cp.begin(), s2cp.end());
    if (s1cp != s2cp)
      return false;

    // 一直剪到这里，判断前提:
    // 如果s1和s2是scramble的话，那么必然存在一个在s1上的
    // 长度l1，将s1分成s11和s12两段，同样有s21和s22。
    // 那么要么s11和s21是scramble的并且s12和s22是scramble的；
    // 要么s11和s22是scramble的并且s12和s21是scramble的。
    for (int i = 1; i < s1.size(); i++) {
      auto s1sub1 = s1.substr(0, i);
      auto s2sub1 = s2.substr(0, i);
      auto s1sub2 = s1.substr(i);
      auto s2sub2 = s2.substr(i);

      if (isScramble(s1sub1, s2sub1) && isScramble(s1sub2, s2sub2))
        return true;
      auto s2sub3 = s2.substr(s2.size() - i);
      auto s2sub4 = s2.substr(0, s2.size() - i);
      if (isScramble(s1sub1, s2sub3) && isScramble(s1sub2, s2sub4))
        return true;
    }

    return false;
  }
};
