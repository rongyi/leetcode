// http://leetcode.com/problems/latest-time-by-replacing-hidden-digits/description/
#include "xxx.h"

class Solution {
public:
  string maximumTime(string time) {
    // hh:mm
    for (int i = 0; i < time.size(); ++i) {
      if (time[i] == '?') {
        // hour
        if (i < 2) {
          if (i == 0) {
            // 还需要看下一步的得数多少
            if (time[i + 1] == '?' || time[i + 1] < '4') {
              time[i] = '2';
            } else {
              time[i] = '1';
            }
          } else {
            if (time[i - 1] != '2') {
              time[i] = '9';
            } else {
              time[i] = '3';
            }
          }
        } else { // minute
          if (i == 3) {
            time[i] = '5';
          } else {
            time[i] = '9';
          }
        }
      }
    }

    return time;
  }
};
