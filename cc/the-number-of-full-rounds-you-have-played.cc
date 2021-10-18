// http://leetcode.com/problems/the-number-of-full-rounds-you-have-played/description/
#include "xxx.h"

class Solution {
public:
  int numberOfRounds(string startTime, string finishTime) {
    // aa:bb
    int start_hour = stoi(startTime.substr(0, 2));
    int start_min = stoi(startTime.substr(3));

    int finish_hour = stoi(finishTime.substr(0, 2));
    int finish_min = stoi(finishTime.substr(3));

    // make it bigger
    if ((finish_hour * 60 + finish_min) < (start_hour * 60 + start_min)) {
      finish_hour += 24;
    }
    // full hours
    int ret = 0;
    int full_hour = (finish_hour - start_hour - 1);
    if (full_hour >= 0) {
      ret += full_hour * 4;

      ret += (60 - start_min) / 15;
      ret += finish_min / 15;

      return ret;
    }

    // no full time hour
    // check the first, and check the end at round 15
    // <= 0 means there is no full 15 interval
    ret = ((finish_min / 15) * 15 - (start_min + 14) / 15 * 15) / 15;

    return ret <= 0 ? 0 : ret;
  }
};

int main() {
  Solution so;
  so.numberOfRounds("00:47", "00:57");
}
