// http://leetcode.com/problems/generate-a-string-with-characters-that-have-odd-counts/description/
#include "xxx.hpp"

class Solution {
public:
  string generateTheString(int n) {
    string ret(n, 'a');

    if ((n & 1) == 0) {
      ret.pop_back();
      ret.push_back('b');
    }

    return ret;
  }
};
