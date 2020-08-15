// http://leetcode.com/problems/self-dividing-numbers/description/
#include "xxx.h"

class Solution {
public:
  vector<int> selfDividingNumbers(int left, int right) {
    vector<int> ret;
    for (int i = left; i <= right; i++) {
      if (isSelfDriving(i)) {
        ret.push_back(i);
      }
    }
    return ret;
  }
private:
  bool isSelfDriving(int num) {
    int cp = num;
    while (num) {
      int d = num % 10;
      if (d == 0 || cp % d != 0) {
        return false;
      }
      num /= 10;
    }
    return true;
  }
};
