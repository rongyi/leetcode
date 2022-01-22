// http://leetcode.com/problems/super-palindromes/description/
#include "xxx.hpp"

class Solution {
public:
  int superpalindromesInRange(string L, string R) {
    int ret = 0;
    long l = stol(L);
    long r = stol(R);
    // 偶数情况
    recur("", ret, l, r);
    // 奇数情况
    for (char c = '0'; c <= '9'; c++) {
      recur(string(1, c), ret, l, r);
    }

    return ret;
  }
private:
  void recur(string cur, int &ret, long &l, long &r) {
    if (cur.size() > 9) {
      return;
    }
    if (!cur.empty() && cur[0] != '0') {
      long cur_num = stol(cur);
      long cur_squar = cur_num * cur_num;
      if (cur_squar > r) {
        return;
      }
      if (cur_squar >= l && isp(to_string(cur_squar))) {
        ret++;
      }
    }

    for (char c = '0'; c <= '9'; c++) {
      recur(string(1, c) + cur + string(1, c), ret, l, r);
    }
  }
  bool isp(string s) {
    int i = 0;
    int j = s.size() - 1;
    while (i < j) {
      if (s[i] != s[j]) {
        return false;
      }
      i++;
      j--;
    }
    return true;
  }
};
