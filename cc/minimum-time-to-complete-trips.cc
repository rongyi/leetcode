// https://leetcode.com/problems/minimum-time-to-complete-trips/
#include "xxx.hpp"

class Solution {
public:
  long long minimumTime(vector<int> &time, int totalTrips) {
    long long l = 0;
    long long r = numeric_limits<long long>::max() / time.size();
    while (l < r) {
      long long mid = (l + r) / 2;
      long long cur_trips = 0;
      for (auto t : time) {
        cur_trips += mid / t;
      }
      if (cur_trips < totalTrips) {
        l = mid + 1;
      } else {
        r = mid;
      }
    }

    return l;
  }
};
