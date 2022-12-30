// https://leetcode.com/problems/maximum-value-of-a-string-in-an-array/
#include "xxx.hpp"

class Solution {
public:
  int maximumValue(vector<string> &strs) {
    int ret = 0;
    auto digiOnly = [](string &s) {
      for (auto &c : s) {
        if (!isdigit(c)) {
          return false;
        }
      }
      return true;
    };
    for (auto &s : strs) {
      if (digiOnly(s)) {
        int i = 0;
        for (; i < s.size() && s[i] == '0'; ++i) {
          ;
        }
        if (i < s.size()) {
          ret = max(ret, stoi(s.substr(i)));
        }

      } else {
        ret = max(ret, (int)s.size());
      }
    }

    return ret;
  }
};
