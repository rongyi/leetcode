// https://leetcode.com/problems/count-distinct-numbers-on-board/
#include "xxx.hpp"

class Solution {
public:
  int distinctIntegers(int n) {
    set<int> uniq{n};
    int prev_len = uniq.size();
    while (true) {
      for (int i = 2; i < n; ++i) {
        for (auto v : uniq) {
          if ((v % i) == 1) {
            uniq.insert(i);
          }
        }
      }
      if (uniq.size() == prev_len) {
        break;
      }
      prev_len = uniq.size();
    }

    return uniq.size();
  }
};
