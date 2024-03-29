// http://leetcode.com/problems/wildcard-matching/description/
#include "xxx.hpp"

class Solution {
public:
  bool isMatch(string s, string p) {
    int ssz = s.size();
    int psz = p.size();
    vector<vector<int>> dp(ssz + 1, vector<int>(psz + 1, 0));
    dp[0][0] = 1;
    // '*'
    for (int j = 1; j <= psz && p[j - 1] == '*'; j++) {
      dp[0][j] = dp[0][j - 1];
    }
    // *
    // dp[i][j] when p[j - 1] == '*'
    // dp[i][j - 1] -> dp[i][j]
    // dp[i - 1][j] -> dp[i][j]
    for (int i = 1; i <= ssz; i++) {
      for (int j = 1; j <= psz; j++) {
        if (p[j - 1] == '*') {
          dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
        } else {
          dp[i][j] =
              ((s[i - 1] == p[j - 1]) || p[j - 1] == '?') && dp[i - 1][j - 1];
        }
      }
    }

    return dp[ssz][psz];
  }
};

class Solution2 {
public:
  bool isMatch(string s, string p) { return matchChar(s.c_str(), p.c_str()); }
  bool matchChar(const char *s, const char *p) {
    const char *scur = s, *pcur = p, *sstar = nullptr, *pstar = nullptr;
    while (*scur) {
      // 正常匹配，各自自增，没什么好说，
      if (*scur == *pcur || *pcur == '?') {
        ++scur;
        ++pcur;
      } else if (
          *pcur ==
          '*') { // 表示有*加持，这里的条件先后也是有讲究的，遇到一个*，之前的
                 // *匹配过程就结束了，翻过去了
        // 为了下一轮不再匹配 '*'
        // 这个条件所以这里把pcur移走了，但是位置通过pstar保留了，所以这里下一轮不是问题
        pstar = pcur++;
        sstar = scur;
      } else if (pstar) {
        // 这里已经不等了，进一步看是否有*加持，如果有，则继续用*来满足
        // 所以一个*在没遇到相等的情况下能把S消耗殆尽，S最先到头
        // 一遇到不等的情况，就把p拉到*后面的那个字符重新来过，诠释了匹配零个或多个，
        // 意思就是为了能相等，s随便消耗
        pcur = pstar + 1;
        // 不等的情况下，一直消耗S
        scur = ++sstar;
      } else
        return false;
    }
    // 这里就要看看后面p还剩不剩？
    while (*pcur == '*')
      ++pcur;
    return !*pcur;
  }
};

int main() {
  Solution so;
  // "acdcb"
  // "a*c?b"
  auto ret = so.isMatch("abcceb", "*c*b");
  cout << ret << endl;
}
