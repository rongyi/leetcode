// http://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/
#include "xxx.hpp"

class Solution {
public:
  int numberOfSubstrings(string s) {
    int count[3] = {0, 0, 0};
    int i = 0;
    int ret = 0;
    // aaaaaabc
    // i      j
    //       i
    // count += i
    for (int j = 0; j < s.size(); j++) {
      ++count[s[j] - 'a'];
      while (count[0] && count[1] && count[2]) {
        --count[s[i++] - 'a'];
      }
      ret += i;
    }

    return ret;
  }
};
