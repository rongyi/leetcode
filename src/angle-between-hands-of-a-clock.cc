// http://leetcode.com/problems/angle-between-hands-of-a-clock/description/
#include "xxx.h"

class Solution {
public:
  double angleClock(int hour, int minutes) {
    double ret = 0;
    if (minutes == 0) {
      ret = hour * 30;
    } else {
      ret = ((minutes / 5 - hour + 12) % 12) * (double)30;
      ret += (minutes % 5) / (double)5 * 30;
      ret -= (double)minutes * 0.5;
      if (ret < 0) {
        ret = -ret;
      }
    }

    if (ret > 180) {
      ret = 360 - ret;
    }
    return ret;
  }
};

int main() {
  Solution so;
  cout << so.angleClock(1, 4) << endl;
}
