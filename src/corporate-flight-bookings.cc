// http://leetcode.com/problems/corporate-flight-bookings/description/
#include "xxx.h"

class Solution {
public:
  vector<int> corpFlightBookings(vector<vector<int>> &bookings, int n) {
    vector<int> ret(n, 0);
    for (auto &vec : bookings) {
      ret[vec[0] - 1] += vec[2];
      if (vec[1] < n) {
        ret[vec[1]] -= vec[2];
      }
    }

    for (int i = 1; i < n; ++i) {
      ret[i] += ret[i - 1];
    }

    return ret;
  }
};
