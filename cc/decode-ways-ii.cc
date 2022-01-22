// http://leetcode.com/problems/decode-ways-ii/description/
#include "xxx.hpp"

class Solution {
public:
  // dp[i] = dp[i-1]* f(s.substr(i,1)) + dp[i-2]* f(s.substr(i-1, 2))
  int numDecodings(string s) {
    const int n = s.size();
    const int mod = pow(10, 9) + 7;
    long f1 = 1;
    long f2 = count(s.substr(0, 1));

    for (int i = 1; i < n; i++) {
      long f3 = (f2 * count(s.substr(i, 1))) + (f1 * count(s.substr(i - 1, 2)));
      f1 = f2;
      f2 = f3 % mod;
    }
    return f2;
  }
  int count(string s) {
    if (s.size() == 1) {
      if (s[0] == '*') {
        // 1 ~ 9
        return 9;
      }
      // first can not be 0
      return s[0] == '0' ? 0 : 1;
    }
    // two char case
    // 11, 12 ... 19, 21 21 ... 26
    // 20 is not valid, because * can only be 1 ~ 9
    if (s == "**") {
      return 15;
    } else if (s[1] == '*') {
      // 后面为*的case
      if (s[0] == '1') {
        return 9;
      }
      // 为2的情况有6中，否则不合法
      return s[0] == '2' ? 6 : 0;
    } else if (s[0] == '*') {
      // 后面<= '6' 时可取1 , 2, 否则只能取1
      return s[1] <= '6' ? 2 : 1;
    }
    int cur = stoi(s);
    // 两位数的合法情况
    return cur >= 10 && cur <= 26 ? 1 : 0;
  }
};
