// http://leetcode.com/problems/guess-number-higher-or-lower/description/
#include "xxx.h"

// Forward declaration of guess API.
// @param num, your guess
// @return
// -1 if my number is lower,
// 1 if my number is higher,
// otherwise return 0
int guess(int num);

class Solution {
public:
  int guessNumber(int n) {
    int start = 1;
    int end = n;
    while (start <= end) {
      auto mid = start + (end - start) / 2;
      auto check = guess(mid);
      if (check == 0) {
        return mid;
      } else if (check < 0) {
        end = mid;
      } else {
        start = mid + 1;
      }
    }
    return -1;
  }
};
