// http://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/description/
#include "xxx.h"

class Solution {
public:
  int concatenatedBinary(int n) {
    const int mod = pow(10, 9) + 7;
    long long ret = 0;
    for (int i = 1; i <= n; ++i) {
      auto len = bitcount(i);
      // 不要被二进制带进去,看二进制需要左移的空间位数是多少，然后移位即可。
      ret = ((ret << len) % mod + i) % mod;
    }

    return ret;
  }

private:
  int bitcount(int n) {
    int ret = 0;
    while (n) {
      n >>= 1;
      ++ret;
    }
    return ret;
  }
};

int main() {
  Solution so;
  cout << so.concatenatedBinary(3) << endl;
}
