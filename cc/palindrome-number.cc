// http://leetcode.com/problems/palindrome-number/description/
#include "xxx.hpp"

class Solution {
public:
  bool isPalindrome(int x) {
    if (x < 0) {
      return false;
    }
    if (x == 0) {
      return true;
    }
    auto count = [](int i) {
      int ret = 0;
      while (i) {
        ret++;
        i /= 10;
      }
      return ret;
    };

    int dc = count(x);
    int align = 1;
    while (--dc) {
      align *= 10;
    }

    while (x) {
      auto high = x / align;
      auto low = x % 10;
      if (high != low) {
        return false;
      }
      // 斩掉最高位，最低位
      x %= align;
      x /= 10;

      align /= 100;
    }
    return true;
  }
};

int main() {
  Solution so;
  auto ret = so.isPalindrome(0);
  cout << ret << endl;
}
