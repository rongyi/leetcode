// http://leetcode.com/problems/car-fleet/description/
#include "xxx.hpp"

class Solution {
public:
  int carFleet(int target, vector<int> &position, vector<int> &speed) {
    map<int, double> durations;
    for (int i = 0; i < position.size(); i++) {
      durations[-position[i]] = (double)(target - position[i]) / speed[i];
    }
    int ret = 0;
    double cur = 0;
    for (auto kv : durations) {
      if (kv.second > cur) {
        cur = kv.second;
        ret++;
      }
    }
    return ret;
  }
};
