// http://leetcode.com/problems/second-largest-digit-in-a-string/description/
#include "xxx.h"

class Solution {
public:
  int secondHighest(string s) {
    set<int> order;
    for (auto c : s) {
      if (isdigit(c)) {
        order.insert(c - '0');
      }
    }
    if (order.size() < 2) {
      return -1;
    }
    return *prev(prev(order.end()));
  }
};
