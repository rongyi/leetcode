// http://leetcode.com/problems/greatest-common-divisor-of-strings/description/
#include "xxx.h"

class Solution {
public:
  string gcdOfStrings(string str1, string str2) {
    if (str1.size() < str2.size()) {
      return gcdOfStrings(str2, str1);
    }
    if (str2.empty()) {
      return str1;
    }
    if (str1.substr(0, str2.size()) != str2) {
      return "";
    }

    return gcdOfStrings(str1.substr(str2.size()), str2);
  }
};
