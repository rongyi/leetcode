// http://leetcode.com/problems/valid-palindrome/description/
#include "one.h"

class Solution {
public:
  bool isPalindrome(string s) {
    const int m = s.size();
    if (m == 0) {
      return true;
    }

    int left = 0;
    int right = m - 1;
    while (left < right) {
      auto l = tolower(s[left]);
      auto r = tolower(s[right]);
      if (!isalnum(l)) {
        left++;
        continue;
      }
      if (!isalnum(r)) {
        right--;
        continue;
      }
      if (l != r) {
        // cout << char(l) << " " << char(r) << endl;
        return false;
      }
      left++;
      right--;
    }
    return true;
  }
};

int main() {
  Solution so;
  auto ret = so.isPalindrome("0P");
  cout << ret << endl;
}
