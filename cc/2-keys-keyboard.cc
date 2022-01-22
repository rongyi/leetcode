// http://leetcode.com/problems/2-keys-keyboard/description/
#include "xxx.hpp"

class Solution {
public:
  int minSteps(int n) {
    if (n == 1) {
      return 0;
    }
    // 粘贴1这种情况
    if (n < 5) {
      return n;
    }
    // to get AA, one copy one paste
    int ret = 2;
    int len = 2;
    int copy_len = 1; // just 'A'
    while (len < n) {
      if (n % len == 0) {
        copy_len = len;
        // one copy, one paste
        ret += 2;
        len = len * 2;
      } else {
        len += copy_len;
        ret++;
      }
    }
    return ret;
  }
};

int main() {
  Solution so;
  auto ret = so.minSteps(9);
  cout << ret << endl;
}
