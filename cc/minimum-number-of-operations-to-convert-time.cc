// https://leetcode.com/problems/minimum-number-of-operations-to-convert-time/
#include "xxx.hpp"

class Solution {
public:
  int convertTime(string current, string correct) {
    // 00:00
    // conv translate to min
    auto conv = [](string s) -> int {
      return (s[0] - '0') * 10 + (s[1] - '0');
    };
    int start_min = conv(current) * 60 + conv(current.substr(3));
    int end_min = conv(correct) * 60 + conv(correct.substr(3));

    int ret = 0;
    auto dist = end_min - start_min;
    while (dist > 0) {
      if (dist >= 60) {
        ret += dist / 60;
        dist %= 60;
      } else if (dist >= 15) {
        ret += dist / 15;
        dist %= 15;
      } else if (dist >= 5) {
        ret += dist / 5;
        dist %= 5;
      } else {
        ret += dist;
        break;
      }
    }

    return ret;
  }
};

