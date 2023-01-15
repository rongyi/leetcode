// https://leetcode.com/problems/maximize-the-minimum-powered-city/
#include "xxx.hpp"

using ll = long long;
class Solution {
public:
  long long maxPower(vector<int> &stations, int r, int k) {
    ll left = 0;
    ll right = accumulate(stations.begin(), stations.end(), 0ll) + k;
    ll ret = 0;
    while (left <= right) {
      ll mid = left + (right - left) / 2;
      if (isGood(stations, r, k, mid)) {
        ret = mid;
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }

    return ret;
  }

private:
  // assume mininum pow is cur, let's check we can staify or not
  bool isGood(vector<int> &stations, int r, int k, ll cur) {
    int sz = stations.size();
    ll win_power = accumulate(stations.begin(), stations.begin() + r, 0LL);
    vector<int> new_plants(sz, 0);

    for (int i = 0; i < sz; ++i) {
      if (i + r < sz) {
        win_power += stations[i + r];
      }
      if (win_power < cur) {
        ll needed = cur - win_power;
        if (needed > k) {
          // not enough budget
          return false;
        }
        new_plants[min(sz - 1, i + r)] += needed;
        k -= needed;
        win_power = cur;
      }

      if ((i - r) >= 0) {
        win_power -= stations[i - r] + new_plants[i - r];
      }
    }

    return true;
  }
};
