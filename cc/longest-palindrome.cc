// http://leetcode.com/problems/longest-palindrome/description/
#include "xxx.h"

class Solution {
public:
  // 就是count所有字符，然后把偶数的算作两边的
  // 如果有奇数字符，就在中间加一个奇数字符。并且就
  // 只能加这么一次
  int longestPalindrome(string s) {
    unordered_map<char, int> count;
    bool has_odd = false;
    for (auto c : s) {
      count[c]++;
    }
    int ret = 0;
    for (auto kv : count) {
      if (!has_odd && (kv.second & 1)) {
        has_odd = true;
      }
      ret += kv.second / 2;
    }
    ret *= 2;

    if (has_odd) {
      ++ret;
    }
    return ret;
  }
};
