// http://leetcode.com/problems/count-binary-substrings/description/
#include "xxx.h"

class Solution {
public:
  // First, I count the number of 1 or 0 grouped consecutively.
  // For example "0110001111" will be [1, 2, 3, 4].

  // Second, for any possible substrings with 1 and 0 grouped consecutively, the number of valid substring will be the minimum number of 0 and 1.
  // For example "0001111", will be min(3, 4) = 3, ("01", "0011", "000111")
  int countBinarySubstrings(string s) {
    int ret = 0;
    int prev = 0;
    int cur = 1;
    for (int i = 1; i < s.size(); i++) {
      if (s[i] == s[i - 1]) {
        cur++;
      } else {
        ret += min(cur, prev);
        prev = cur;
        cur = 1;
      }
    }
    // last round
    return ret + min(cur, prev);
  }
  int countBinarySubstringsTLE(string s) {
    const int n = s.size();
    int ret = 0;
    for (int i = 0; i < n; i++) {
      int len = 2;
      while (i + len <= n) {
        string cur = s.substr(i, len);
        if (is_group_even(cur)) {
          // cout << cur << endl;
          ret++;
          len *= 2;
        } else {
          len += 2;
        }
      }
    }
    return ret;
  }

private:
  // string s is all even, so we don't check length
  bool is_group_even(string &s) {
    bool is_begin_zero = s[0] == '0';
    int half = s.size() / 2;
    string first = s.substr(0, half);
    string second = s.substr(half);
    string all_zero(half, '0');
    string all_one(half, '1');
    if (is_begin_zero) {
      return (first == all_zero) && (second == all_one);
    }
    return (first == all_one) && (second == all_zero);
  }
};
