// https://leetcode.com/problems/the-latest-time-to-catch-a-bus/
#include "xxx.hpp"

class Solution {
public:
  int latestTimeCatchTheBus(vector<int> &buses, vector<int> &passengers,
                            int capacity) {
    sort(buses.begin(), buses.end());
    sort(passengers.begin(), passengers.end());
    // fill all bus, and check the last bus case
    // i for bus index, j for passengers
    int m = buses.size();
    int n = passengers.size();
    for (int i = 0, j = 0; i < m; ++i) {
      int cnt = 0;

      while (j < n && passengers[j] <= buses[i] && cnt < capacity) {
        j++;
        cnt++;
      }
      // last bus, must in!
      if (i == m - 1) {
        // then the latest time is the bust departure time
        if (cnt < capacity) {
          int t = buses[i];
          // incase some one take this time, we shift from this time to prev
          for (int k = j - 1; k >= 0 && passengers[k] == t; k--, t--) {
            ;
          }

          return t;
        } else {
          // full of passengers, be the front of last one
          int t = passengers[j - 1] - 1;

          // in case some one take this position
          for (int k = j - 2; k >= 0 && passengers[k] == t; t--, k--) {
            ;
          }

          return t;
        }
      }
    }

    return -1;
  }
};
