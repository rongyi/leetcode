// http://leetcode.com/problems/equal-rational-numbers/description/
#include "xxx.h"

class Solution {
public:
  bool isRationalEqual(string S, string T) {
    // tranform to double
    return f(S) == f(T);
  }

private:
  double f(string &s) {
    auto i = s.find("(");
    if (i != string::npos) {
      string base = s.substr(0, i);
      string rep = s.substr(i + 1, s.find(')') - i - 1);
      for (int j = 0; j < 20; ++j) {
        base += rep;
      }
      return stod(base);
    }

    return stod(s);
  }
};
