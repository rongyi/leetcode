// https://leetcode.com/problems/minimum-time-to-type-word-using-special-typewriter/
#include "xxx.hpp"

class Solution {
public:
  int minTimeToType(string word) {
    int prev = 'a';
    int ret = word.size();
    for (auto c : word) {
      // anti clockwise
      int aclk = (c - prev + 26) % 26;
      // clockwise rotate
      int clk = (26 - (c - prev) + 26) % 26;
      ret += min(aclk, clk);
      prev = c;
    }

    return ret;
  }
};

int main() {
  Solution so;
  int ret = so.minTimeToType("bza");
  cout << ret << endl;
}
