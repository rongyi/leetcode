// http://leetcode.com/problems/elimination-game/description/
#include "xxx.h"

class Solution {
public:
  int lastRemaining(int n) {
    // Let f(n)=f(1,...,n) and b(n)=b(1,...,n) be the last number remaining when removing forward and backward, respectively. Then:
    //
    // f(1) = b(1) = 1
    //
    // f(2k) = f(1,2,...,2k-1,2k) = b(2,4,...,2k) = 2b(k)
    // f(2k+1) = f(1,2,...,2k-1,2k,2k+1) = b(2,4,...,2k) = 2b(k)
    //
    // b(2k) = b(1,2,...,2k-1,2k) = f(1,3,...,2k-1) = f(2,4,...,2k)-1 = 2f(k)-1
    // b(2k+1) = b(1,2,...,2k-1,2k,2k+1) = f(2,4,...,2k) = 2f(k)

    return recur(true, n);
  }
private:
  int recur(bool left_to_right, int n) {
    if (n == 1) {
      return 1;
    }
    if (left_to_right) {
      return recur(false, n / 2) * 2;
    }
    // from right to left
    if (n & 0x01) {
      return 2 * recur(true, n / 2);
    }
    return 2 * recur(true, n / 2) - 1;
  }
};
