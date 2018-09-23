// http://leetcode.com/problems/palindrome-number/description/
#include "one.h"

class Solution {
public:
  bool isPalindrome(int x) {
    if (x < 0) {
      return false;
    }
    if (x == 0) {
      return true;
    }
    auto cp = x;
    // digit count
    int dc = 0;
    while (x) {
      ++dc;
      x /= 10;
    }
    int align = 1;
    while (--dc) {
      align *= 10;
    }

    x = cp;
    while (x) {
      auto high = x / align;
      auto low = x % 10;
      if (high != low) {
        return false;
      }
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
