// http://leetcode.com/problems/permutation-in-string/description/
#include "xxx.h"

class Solution {
public:
  bool checkInclusionTLE(string s1, string s2) {
    sort(s1.begin(), s1.end());
    do {
      if (s2.find(s1) != string::npos) {
        return true;
      }
    } while (next_permutation(s1.begin(), s1.end()));
    return false;
  }
};
