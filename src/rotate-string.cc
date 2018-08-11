// https://leetcode.com/problems/rotate-string/description/
#include "one.h"

class Solution {
public:
  bool rotateString2(string A, string B) {
    return A.size() == B.size() && (A + A).find(B) != string::npos;
  }
  bool rotateString(string A, string B) {
    if (A.empty() && B.empty()) {
      return true;
    }
    if (A.size() != B.size()) {
      return false;
    }
    for (unsigned i = 0; i < A.size(); i++) {
      if ((A.substr(i, A.size() - 1) + A.substr(0, i)) == B) {
        return true;
      }
    }
    return false;
  }
};
