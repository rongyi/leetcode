// http://leetcode.com/problems/splitting-a-string-into-descending-consecutive-values/description/
#include "xxx.h"

class Solution {
public:
  bool splitString(string s) {
    int sz = s.size();
    int i = 0;
    // jump over leading '0'
    while (i < sz && s[i] == '0') {
      i++;
    }
    for (int j = i; j < sz - 1; ++j) {
      string first = s.substr(i, j - i + 1);
      // cout << first << endl;
      string left = s.substr(j + 1);
      if (split(left, first)) {
        return true;
      }
    }

    return false;
  }

private:
  bool split(string &s, string &prev) {
    if (s.empty()) {
      return true;
    }
    string expect = str_minus_one(prev);
    // then all the left part should be zero too
    if (all_zero(expect)) {
      return all_zero(s);
    }

    auto idx = s.find(expect);
    if (idx == string::npos) {
      return false;
    }
    // 匹配前面必须全部是0才可以
    for (int i = 0; i < idx; ++i) {
      if (s[i] != '0') {
        return false;
      }
    }
    string left = s.substr(idx + expect.size());

    // 看余下的了
    return split(left, expect);
  }
  string str_minus_one(string &s) {
    const int sz = s.size();
    // need borrow?
    // yes
    if (s[sz - 1] == '0') {
      s[sz - 1] = '9';
      int i = sz - 2;
      for (; i >= 0; --i) {
        if (s[i] != '0') {
          s[i] = '0' + (s[i] - '0' - 1);
          break;
        } else {
          s[i] = '9';
        }
      }
      // eliminate the highest zero
      if (i == 0 && s[i] == '0') {
        return s.substr(1);
      }

      return s;
    } else {
      // no
      s[sz - 1] = '0' + (s[sz - 1] - '0' - 1);
      return s;
    }
  }

  bool all_zero(string &s) {
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] != '0') {
        return false;
      }
    }
    return true;
  }
};

int main() {
  Solution so;
  // string input{"0001"};
  // cout << so.str_minus_one(input) << endl;
  cout << so.splitString("10009998") << endl;
}
