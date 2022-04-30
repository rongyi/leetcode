// https://leetcode.com/problems/find-players-with-zero-or-one-losses/
#include "xxx.hpp"

class Solution {
public:
  vector<vector<int>> findWinners(vector<vector<int>> &matches) {
    set<int> wins;
    set<int> losers;
    map<int, int> indgree;

    for (auto &m: matches) {
      wins.insert(m[0]);
      losers.insert(m[1]);
      indgree[m[1]]++;
    }
    vector<int> always_wins;
    vector<int> lose_once;

    for (auto k: wins) {
      if (!losers.count(k)) {
        always_wins.push_back(k);
      }
    }

    for (auto k: losers) {
      if (indgree[k] == 1) {
        lose_once.push_back(k);
      }
    }

    return {always_wins, lose_once};
  }
};
