// https://leetcode.com/problems/number-of-valid-clock-times/
#include "xxx.hpp"

class Solution {
public:
  int countTime(string time) {
    int hour_total = 1;
    int min_total = 1;
    if (time[0] == '?' && time[1] == '?') {
      hour_total = 24;
    } else if (time[0] == '?') {
      // can be '0', '1' '2'
      if (time[1] <= '3') {
        hour_total = 3;
      } else {
        // can be '0' '1'
        hour_total = 2;
      }
    } else if (time[1] == '?') {
      if (time[0] == '2') {
        hour_total = 4;
      } else {
        hour_total = 10;
      }
    }

    if (time[3] == '?' && time[4] == '?') {
      min_total = 60;
    } else if (time[3] == '?') {
      min_total = 6;
    } else if (time[4] == '?') {
      min_total = 10;
    }

    return hour_total * min_total;
  }
};
