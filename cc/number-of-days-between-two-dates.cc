// http://leetcode.com/problems/number-of-days-between-two-dates/description/
#include "xxx.h"

class Solution {
public:
  int daysBetweenDates(string date1, string date2) {
    int ret = 0;

    auto d1 = parse(date1);
    auto d2 = parse(date2);
    vector<int> start = d1;
    vector<int> end = d2;
    auto diff = cmp(d1, d2);
    if (diff == 0) {
      return 0;
    } else if (diff == 1) {
      start = d2;
      end = d1;
    }

    // year count
    for (int i = 0; i < (end[0] - start[0]); ++i) {
      ret += 365;
      if (isLeapYear(i + start[0])) {
        ++ret;
      }
    }
    ret -= dayOfYear(start);
    ret += dayOfYear(end);
    return ret;
  }

private:
  vector<int> parse(string date) {
    auto ystr = date.substr(0, 4);
    auto mstr = date.substr(5, 2);
    auto dstr = date.substr(8, 2);
    int y = stoi(ystr);
    int m = stoi(mstr);
    int d = stoi(dstr);
    return vector<int>{y, m, d};
  }
  int cmp(vector<int> &l, vector<int> &r) {
    if (l[0] < r[0]) {
      return -1;
    } else if (l[0] > r[0]) {
      return 1;
    }

    if (l[1] < r[1]) {
      return -1;
    } else if (l[1] > r[1]) {
      return 1;
    }

    if (l[2] < r[2]) {
      return -1;
    } else if (l[2] > r[2]) {
      return 1;
    }
    return 0;
  }
  int dayOfYear(vector<int> &d) {
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int prefixsum[13] = {};
    for (int i = 1; i < 13; i++) {
      prefixsum[i] = prefixsum[i - 1] + days[i - 1];
    }

    auto ret = prefixsum[d[1] - 1] + d[2];
    if (d[1] > 2 && isLeapYear(d[0])) {
      ++ret;
    }
    return ret;
  }
  bool isLeapYear(int year) {
    return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
  }
};

int main() {
  Solution so;
  auto ret = so.daysBetweenDates("2020-01-15", "2019-12-31");
  cout << ret << endl;
}
