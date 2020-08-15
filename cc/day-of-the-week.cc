// http://leetcode.com/problems/day-of-the-week/description/
#include "xxx.h"

class Solution {
public:
  string dayOfTheWeek(int day, int month, int year) {
    string dayOfWeekNames[7] = {"Sunday",   "Monday", "Tuesday", "Wednesday",
                                "Thursday", "Friday", "Saturday"};
    // 1971 1.1 is friday
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int prefixsum[13] = {};
    for (int i = 1; i < 13; i++) {
      prefixsum[i] = prefixsum[i - 1] + days[i - 1];
    }
    int total_days = 4 + day + ((month > 2 && isLeapYear(year)) ? 1 : 0);
    for (int i = 1971; i < year; ++i) {
      total_days += 365;
      if (isLeapYear(i)) {
        ++total_days;
      }
    }
    // don't forget the month
    total_days += prefixsum[month - 1];
    return dayOfWeekNames[total_days % 7];
  }

private:
  bool isLeapYear(int year) {
    return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
  }
};
