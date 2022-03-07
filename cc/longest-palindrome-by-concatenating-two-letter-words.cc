// https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/
#include "xxx.hpp"

class Solution {
public:
  int longestPalindrome(vector<string> &words) {
    map<string, int> count;
    for (auto &w : words) {
      ++count[w];
    }
    int ret = 0;
    bool middle = false;
    for (auto &kv : count) {
      if (kv.second == 0) {
        continue;
      }
      string rev = kv.first;
      swap(rev[0], rev[1]);
      if (count[rev] > 0) {
        if (rev[0] != rev[1]) {
          ret += min(kv.second, count[rev]) * 4;
          count[rev] = 0;
        } else {
          ret += (kv.second / 2) * 4;
          // note the operation |=
          // or you can write as
          // if (!middle) {
          // middle = (kv.second & 1) == 1;
          // }
          // just don't make middle from true to false
          middle |= (kv.second & 1) == 1;
          count[rev] = 0;
        }
        kv.second = 0;
      }
    }
    if (middle) {
      ret += 2;
    }
    return ret;
  }
};

int main() {
  Solution so;
  vector<string> input{"lc", "cl", "gg"};
  so.longestPalindrome(input);
}
