// https://leetcode.com/problems/number-of-senior-citizens/
#include "xxx.hpp"

class Solution {
public:
  int countSeniors(vector<string> &details) {
    auto f = [](string &s) -> int {
      auto age = s.substr(11, 2);
      return stod(age);
    };
    int cnt = 0;
    for (auto &d : details) {
      if (f(d) > 60) {
        cnt++;
      }
    }

    return cnt;
  }
};
