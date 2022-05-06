// https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks/
#include "xxx.hpp"

class Solution {
public:
  int minimumRounds(vector<int> &tasks) {
    map<int, int> cnt;
    for (auto &t : tasks) {
      ++cnt[t];
    }
    int total_rounds = 0;
    for (auto &kv : cnt) {
      if (kv.second < 2) {
        return -1;
      }
      if (kv.second % 3 == 0) {
        total_rounds += kv.second / 3;
      } else {
        total_rounds += kv.second / 3 + 1;
      }
    }

    return total_rounds;
  }
};
