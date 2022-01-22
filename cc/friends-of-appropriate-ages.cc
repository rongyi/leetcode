// http://leetcode.com/problems/friends-of-appropriate-ages/description/
#include "xxx.hpp"

class Solution {
public:
  int numFriendRequests(vector<int> &ages) {
    unordered_map<int, int> count;
    for (auto age : ages) {
      count[age]++;
    }
    int ret = 0;
    for (auto kv : count) {
      for (auto kv2 : count) {
        if (request(kv.first, kv2.first)) {
          if (kv.first == kv2.first) {
            ret += kv.second * (kv2.second - 1);
          } else {
            ret += kv.second * kv2.second;
          }
        }
      }
    }

    return ret;
  }
  bool request(int a, int b) {
    return !((b <= 0.5 * a + 7) || (b > a) || (b > 100 && a < 100));
  }
};
