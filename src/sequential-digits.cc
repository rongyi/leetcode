// http://leetcode.com/problems/sequential-digits/description/
#include "xxx.h"

class Solution {
public:
  vector<int> sequentialDigits(int low, int high) {
    vector<int> ret;

    const int start_digits = digitCount(low);
    const int end_digits = digitCount(high);
    for (int cur_dc = start_digits; cur_dc <= end_digits; cur_dc++) {
      // no need to start from the first digit of low
      // stupid start from 1
      for (int start = 1; start <= 10 - cur_dc; start++) {
        int cur = gennum(start, cur_dc);
        if (cur < low) {
          continue;
        }

        if (cur > high) {
          break;
        }
        ret.push_back(cur);
      }
    }

    return ret;
  }

public:
  int gennum(int start, int dc) {
    vector<int> digits{};
    for (int i = 0; i < dc; i++) {
      digits.push_back(start++);
    }

    int ret = 0;
    for (auto &num : digits) {
      ret = ret * 10 + num;
    }

    return ret;
  }
  int digitCount(int n) {
    int ret = 0;

    while (n) {
      ++ret;
      n /= 10;
    }

    return ret;
  }
};
