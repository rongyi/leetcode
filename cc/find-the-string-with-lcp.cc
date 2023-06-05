// https://leetcode.com/problems/find-the-string-with-lcp/
#include "xxx.hpp"

class Solution {
public:
  string findTheString(vector<vector<int>> &lcp) {
    int sz = lcp.size();
    int c = 0;
    // if guess[i] = guess[j]
    // so lcp[i][j] = lcp[i + 1][j + 1];
    vector<int> guess(sz, 0);
    for (int i = 0; i < sz; i++) {
      // already fill
      if (guess[i]) {
        continue;
      }
      // try all possibles
      if (++c > 26) {
        return "";
      }
      // start with i, and find all lcp[i][j] which is > 0
      for (int j = i; j < sz; ++j) {
        if (lcp[i][j] > 0) {
          guess[j] = c;
        }
      }
    }

    for (int i = 0; i < sz; i++) {
      for (int j = 0; j < sz; ++j) {
        // next val exist?
        // else 0
        int next_val = 0;
        if (i + 1 < sz && j + 1 < sz) {
          next_val = lcp[i + 1][j + 1];
        }
        int expect = 0;
        if (guess[i] == guess[j]) {
          expect = next_val + 1;
        }

        if (lcp[i][j] != expect) {
          return "";
        }
      }
    }
    string ret;
    for (auto c : guess) {
      ret += 'a' + c - 1;
    }

    return ret;
  }
};
