// http://leetcode.com/problems/simplified-fractions/description/
#include "xxx.hpp"

class Solution {
public:
  vector<string> simplifiedFractions(int n) {
    vector<string> ret;
    // i > 1
    auto minform = [](int a, int b) -> bool {
      for (int i = 2; i <= a; i++) {
        if (a % i == 0 && b % i == 0) {
          return false;
        }
      }
      return true;
    };

    for (int i = 2; i <= n; ++i) {
      for (int j = 1; j < i; ++j) {
        if (j == 1 || minform(j, i)) {
          ret.push_back(to_string(j) + "/" + to_string(i));
        }
      }
    }

    return ret;
  }
};
