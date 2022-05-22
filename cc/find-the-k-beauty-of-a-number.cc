// https://leetcode.com/problems/find-the-k-beauty-of-a-number/
#include "xxx.hpp"

class Solution {
public:
  int divisorSubstrings(int num, int k) {
    string s = to_string(num);
    int sz = s.size();
    int cnt = 0;
    for (int i = 0; i + k - 1 < sz; ++i) {
      string cur = s.substr(i, k);
      int curi = stoi(cur);

      if (curi == 0) {
        continue;
      }

      if (num % curi == 0) {
        cnt++;
      }
    }

    return cnt;
  }
};
