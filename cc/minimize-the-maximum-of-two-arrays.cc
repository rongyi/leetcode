// https://leetcode.com/problems/minimize-the-maximum-of-two-arrays/
#include "xxx.hpp"

class Solution {
public:
  // https://leetcode.com/problems/minimize-the-maximum-of-two-arrays/solutions/2947016/binary-search-on-answer-intuition-approach-explained-c/?orderBy=most_votes
  int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
    int l = 1;
    int r = numeric_limits<int>::max();
    int comon = lcm(divisor1, divisor2);

    while (l <= r) {
      int mid = l + (r - l) / 2;
      int a = mid / divisor1;
      int b = mid / divisor2;
      if (uniqueCnt1 <= mid - a && uniqueCnt2 <= mid - b &&
          (uniqueCnt1 + uniqueCnt2) <= (mid - (mid / comon))) {
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }

    return l;
  }

private:
  int gcd(int a, int b) {
    if (b == 0) {
      return a;
    }
    return gcd(b, a % b);
  }
  int lcm(long long a, long long b) {
    long long tmp = (a / (gcd(a, b))) * b;
    return tmp > numeric_limits<int>::max() ? numeric_limits<int>::max() : tmp;
  }
};
