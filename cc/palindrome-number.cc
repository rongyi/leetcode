// http://leetcode.com/problems/palindrome-number/description/
#include "xxx.hpp"

class Solution {
public:
  bool isPalindrome(int x) {
    if (x < 0) {
      return false;
    }

    long long shift = 1;
    int cp = x;
    while (x) {
      shift *= 10;
      x /= 10;
    }
    shift /= 10;

    x = cp;
    while (x) {
      int l = x / shift;
      int r = x % 10;
      if (l != r) {
        return false;
      }
      x %= shift;
      x /= 10;

      shift /= 100;
    }

    return true;
  }
};

int main() {
  Solution so;
  auto ret = so.isPalindrome(10);
  cout << ret << endl;
}
