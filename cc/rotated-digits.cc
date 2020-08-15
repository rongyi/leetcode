// https://leetcode.com/problems/rotated-digits/description/
#include "xxx.h"

class Solution {
public:
  int rotatedDigits(int N) {
    int ret = 0;
    for (int i = 1; i <= N; ++i) {
      if (valid(i)) {
        ++ret;
      }
    }
    return ret;
  }
private:
  bool valid(const int n) {
    bool ret = false;
    string sn = std::to_string(n);
    for (auto c : sn) {
      if (c == '3' || c == '4' || c == '7') {
        return false;
      }
      if (c == '2' || c == '5' || c == '6' || c == '9') {
        ret = true;
      }
    }
    return ret;
  }
};
