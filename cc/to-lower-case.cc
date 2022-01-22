// http://leetcode.com/problems/to-lower-case/description/
#include "xxx.hpp"

class Solution {
public:
  string toLowerCase(string str) {
    for (int i = 0; i < str.size(); i++) {
      if (isupper(str[i])) {
        str[i] = tolower(str[i]);
      }
    }
    return str;
  }
};
