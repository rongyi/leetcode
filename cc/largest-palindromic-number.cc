// https://leetcode.com/problems/largest-palindromic-number/
#include "xxx.hpp"

class Solution {
public:
  string largestPalindromic(string num) {
    vector<int> cnt(10, 0);
    for (auto &c : num) {
      cnt[c - '0']++;
    }
    bool has_odd = false;
    char odd = '\0';
    bool has_non_zero = false;
    char non_zero = '\0';

    string s1;
    string s2;

    for (int i = 9; i >= 0; --i) {
      if (cnt[i] && !has_non_zero) {
        has_non_zero = true;
        non_zero = '0' + i;
      }
      if ((cnt[i] & 1) && !has_odd) {
        has_odd = true;
        odd = i + '0';
      }
      auto e = cnt[i] / 2;

      // 0 as a special case
      // we will process it after loop
      if (i > 0 && e > 0) {
        s1 += string(e, i + '0');
        s2 += string(e, i + '0');
      }
    }

    // zero can be added
    if (s1.size() > 0 && cnt[0] / 2) {
      s1 += string(cnt[0] / 2, '0');
      s2 += string(cnt[0] / 2, '0');
    }
    reverse(s2.begin(), s2.end());

    string ret{};
    if (has_odd) {
      ret = s1 + string{odd} + s2;
    } else {
      ret = s1 + s2;
    }

    // empty? try our best to add a single digit
    if (ret.empty() && has_non_zero) {
      return string{non_zero};
    }

    return ret;
  }
};

int main(int argc, char *argv[]) {
  Solution so;
  so.largestPalindromic("00000");
  return 0;
}
