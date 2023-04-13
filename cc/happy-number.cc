// http://leetcode.com/problems/happy-number/description/
#include "xxx.hpp"

class Solution {
public:
  bool isHappy(int n) {
    int slow = n;
    int fast = n;
    while (true) {
      slow = nextNum(slow);
      fast = nextNum(fast);
      fast = nextNum(fast);
      if (slow == fast) {
        break;
      }
    }

    return slow == 1;
  }

private:
  int nextNum(int n) {
    int sum = 0;
    while (n) {
      int d = n % 10;
      sum += d * d;
      n /= 10;
    }
    return sum;
  }
};
