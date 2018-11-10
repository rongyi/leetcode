// http://leetcode.com/problems/first-bad-version/description/
#include "simpleone.h"

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
  int firstBadVersion(int n) {
    int left = 0;
    int right = n;
    while (left < right) {
      const int mid = left + (right - left) / 2;
      // 这里的处理函数是 fn[mid] ==> mid + 1
      if (isBadVersion(mid + 1)) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }
    return left + 1;
  }
};
