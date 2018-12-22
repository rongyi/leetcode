// http://leetcode.com/problems/happy-number/description/
#include "xxx.h"

class Solution {
public:
  bool isHappy(int n) {
    if (n == 1) {
      return true;
    }
    unordered_set<int> cache;
    while (true) {
      auto next = happy(n);
      if (cache.find(next) != cache.end()) {
        return next == 1;
      }
      n = next;
      cache.insert(next);
    }
    return false;
  }
  int happy(int n) {
    int sum = 0;
    while (n) {
      auto d = n % 10;
      sum += d * d;
      n /= 10;
    }

    return sum;
  }
};
