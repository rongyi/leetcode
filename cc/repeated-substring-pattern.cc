// http://leetcode.com/problems/repeated-substring-pattern/description/
#include "xxx.hpp"

class Solution {
public:
  bool repeatedSubstringPattern(string s) {
    int sz = s.length();
    for (int i = 1; i < sz / 2 + 1; i++) {
      if ((sz % i) == 0) {
        string cur = s.substr(0, i);
        string repeat{};
        while (repeat.length() < sz) {
          repeat += cur;
        }
        if (s == repeat) {
          return true;
        }
      }
    }
    return false;
  }
};

int main() {
  Solution so;
  auto ret = so.repeatedSubstringPattern("abab");
  cout << ret << endl;
}
