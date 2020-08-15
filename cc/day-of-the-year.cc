// http://leetcode.com/problems/day-of-the-year/description/
#include "xxx.h"

class Solution {
public:
  int dayOfYear(string date) {
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int prefixsum[13] = {};
    for (int i = 1; i < 13; i++) {
      prefixsum[i] = prefixsum[i - 1] + days[i - 1];
    }
    auto ystr = date.substr(0, 4);
    auto mstr = date.substr(5, 2);
    auto dstr = date.substr(8, 2);
    int y = stoi(ystr);
    int m = stoi(mstr);
    int d = stoi(dstr);

    auto ret = prefixsum[m - 1] + d;
    if (m > 2 && isLeapYear(y)) {
      ++ret;
    }
    return ret;
  }
private:
  bool isLeapYear(int year) {
    return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
  }
};
