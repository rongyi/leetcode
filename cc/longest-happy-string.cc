// http://leetcode.com/problems/longest-happy-string/description/
#include "xxx.h"

class Solution {
public:
  string longestDiverseString(int a, int b, int c) {
    return recur(a, b, c, 'a', 'b', 'c');
  }

private:
  string recur(int a, int b, int c, char aa, char bb, char cc) {
    if (a < b) {
      return recur(b, a, c, bb, aa, cc);
    }
    if (b < c) {
      return recur(a, c, b, aa, cc, bb);
    }
    if (b == 0) {
      return string(min(2, a), aa);
    }
    auto use_a = min(2, a);
    auto use_b = a - use_a >= b ? 1 : 0;

    return string(use_a, aa) + string(use_b, bb) +
           recur(a - use_a, b - use_b, c, aa, bb, cc);
  }
};

int main() {
  Solution so;
  so.longestDiverseString(0, 8, 11);
}
