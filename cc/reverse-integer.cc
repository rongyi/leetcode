// http://leetcode.com/problems/reverse-integer/description/
#include "xxx.hpp"

class Solution {
public:
  int reverse(int x) {
    long long i = x;
    bool pos = true;
    if (x < 0) {
      pos = false;
      i *= -1;
    }
    cout << i << endl;
    long long ret = 0;
    // auto max = numeric_limits<int>::max();
    while (i) {
      ret = ret * 10 + i % 10;
      i /= 10;
    }

    if (ret > numeric_limits<int>::max()) {
      return 0;
    }
    if (pos) {
      return ret;
    }

    return -ret;
  }
};

int main() {
  Solution so;
  auto ret = so.reverse(-123);
  cout << ret << endl;
}
