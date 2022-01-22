// http://leetcode.com/problems/x-of-a-kind-in-a-deck-of-cards/description/
#include "xxx.hpp"

class Solution {
public:
  bool hasGroupsSizeX(vector<int> &deck) {
    unordered_map<int, int> count;
    for (auto card : deck) {
      count[card]++;
    }
    int min_count = numeric_limits<int>::max();
    for (auto kv : count) {
      if (kv.second < 2) {
        return false;
      }
      min_count = min(min_count, kv.second);
    }
    for (auto kv : count) {
      bool can = false;
      for (int i = 2; i <= min_count; i++) {
        if (kv.second % i == 0) {
          can = true;
          break;
        }
      }
      if (!can) {
        return false;
      }
    }
    return true;
  }
};
