// http://leetcode.com/problems/reverse-integer/description/
#include "xxx.hpp"

class Solution {
public:
  int reverse(int x) {
    bool is_neg = false;
    if (x < 0) {
      if (x == numeric_limits<int>::min()) {
        return 0;
      }
      is_neg = true;
      x = -x;
    }
    int m = numeric_limits<int>::max();
    int ret = 0;
    while (x) {
      int cur = x % 10;
      if (ret < m / 10 || (ret == m / 10 && cur < m % 10)) {
        ret = ret * 10 + cur;
      } else {
        return 0;
      }
      x /= 10;
    }

    if (is_neg) {
      return -ret;
    }
    return ret;
  }
};

int main() {
  Solution so;
  auto ret = so.reverse(-123);
  cout << ret << endl;
}
