// http://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/description/
#include "xxx.h"

class Solution {
public:
  vector<int> sumZero(int n) {
    vector<int> ret;
    int count = n;
    if (n % 2) {
      --count;
      ret.push_back(0);
    }
    for (int i = 0; i < count / 2; i++) {
      ret.push_back(i + 1);
      ret.push_back(-(i + 1));
    }

    return ret;
  }
};
