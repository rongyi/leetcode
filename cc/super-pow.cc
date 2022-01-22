// http://leetcode.com/problems/super-pow/description/
#include "xxx.hpp"

class Solution {
public:
  // 这其实是数学问题，找到循环的规律即可
  int superPow(int a, vector<int> &b) {
    if (a == 1) {
      return 1;
    }
    if (a == 1337) {
      return 0;
    }
    a %= 1337;

    int count = 1;
    int rem = a;
    unordered_map<int, int> cache;
    while (true) {
      cache[count] = rem;
      count++;
      rem *= a;
      rem %= 1337;
      if (rem == a) {
        break;
      }
    }
    int cycle = cache.size();

    int val = 0;
    int size = b.size();
    for (int i = 0; i < size; i++) {
      val = val * 10 + b[i];
      val = val % cycle;
    }

    return cache[val];
  }
};
