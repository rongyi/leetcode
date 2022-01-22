// http://leetcode.com/problems/minimum-speed-to-arrive-on-time/description/
#include "xxx.hpp"

class Solution {
public:
  int minSpeedOnTime(vector<int> &dist, double hour) {
    int sz = dist.size();
    // 以光速跑，下边界就是以光速跑，时间无限趋近于n - 1，如果比这还小那么不行了，赶不上
    if (hour < sz - 1) {
      return -1;
    }
	// speed
    long l = 1;
    long r = 1e7;

    while (l <= r) {
      auto mid = l + (r - l) / 2;
      // 合法了，收一收看看
	  // OK, let's make it slowly to see can me make it
      if (valid(dist, mid, hour)) {
        r = mid - 1;
      } else {
        // 不合法要放一放
		// should speed up
        l = mid + 1;
      }
    }
    return l > 1e7 ? -1 : l;
  }

private:
  bool valid(vector<int> &dist, int velocity, double hour) {
    double time = 0;
    for (int i = 0; i < dist.size(); ++i) {
      time = ceil(time);
      time += (double)dist[i] / velocity;
      if (time > hour) {
        return false;
      }
    }

    return true;
  }
};
