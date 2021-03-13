// http://leetcode.com/problems/split-two-strings-to-make-palindrome/description/
#include "xxx.h"

class Solution {
public:
  bool checkPalindromeFormation(string a, string b) {
    return docheck(a, b) || docheck(b, a);
  }

private:
  // l
  // ulabbxyz
  // jizcdalu
  //        r

  // Same, l++, r—

  //  l
  // ulabbxyz
  // jizcdalu
  //       r

  // Same, l++, r—

  //   l
  // ulabbxyz
  // jizcdalu
  //      r

  // Same, l++, r—

  //    l
  // ulabbxyz
  // jizcdalu
  //     r

  //  the trick is here, “b” and “d” are different.
  //  That means we have two choice to make it possible
  //  Either cut at l in string a, or cut at r in string b.

  //  try those 2 approaches
  //     lr
  // ula bb ... // <- need check if [l,r] in string a is palindrome
  // ..... alu
  //  or
  // ula .....
  // ... cd alu  // <- need check if [l,r] in string b is palindrome
  //     lr

  bool docheck(string &a, string &b) {
    int l = 0;
    int r = a.size() - 1;
    while (l < r) {
      if (a[l] != b[r]) {
        break;
      }
      l++;
      r--;
    }
    return check(a, l, r) || check(b, l, r);
  }
  bool check(string &s, int l, int r) {
    while (l < r) {
      if (s[l] != s[r]) {
        return false;
      }
      l++;
      r--;
    }
    return true;
  }
};

int main() {
  string a = "ulacfd";
  string b = "jizalu";
  Solution so;
  auto ret = so.checkPalindromeFormation(a, b);
  cout << ret << endl;
}
