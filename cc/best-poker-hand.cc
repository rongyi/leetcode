// https://leetcode.com/problems/best-poker-hand/
#include "xxx.hpp"

class Solution {
public:
  string bestHand(vector<int> &ranks, vector<char> &suits) {
    vector<int> suit_count(4, 0);
    vector<int> rank_count(14, 0);
    for (auto &c : suits) {
      suit_count[c - 'a']++;
    }
    for (int i = 0; i < 4; ++i) {
      if (suit_count[i] == 5) {
        return "Flush";
      }
    }

    for (auto &r : ranks) {
      rank_count[r]++;
    }
    int max_same = 1;
    for (auto &rc : rank_count) {
      max_same = max(max_same, rc);
    }
    if (max_same >= 3) {
      return "Three of a Kind";
    } else if (max_same == 2) {
      return "Pair";
    }

    return "High Card";
  }
};
