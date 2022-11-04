// https://leetcode.com/problems/maximum-matching-of-players-with-trainers/
#include "xxx.hpp"

class Solution {
public:
  int matchPlayersAndTrainers(vector<int> &players, vector<int> &trainers) {
    sort(players.begin(), players.end());
    map<int, int> cnt;
    for (auto &t : trainers) {
      cnt[t]++;
    }

    int ret = 0;

    for (auto p : players) {
      auto it = cnt.lower_bound(p);
      if (it != cnt.end()) {
        ret += 1;
        it->second -= 1;
        if (it->second == 0) {
          cnt.erase(it);
        }
      }
    }

    return ret;
  }
};
