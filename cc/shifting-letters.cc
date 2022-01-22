// http://leetcode.com/problems/shifting-letters/description/
#include "xxx.hpp"

class Solution {
public:
  string shiftingLetters(string S, vector<int> &shifts) {
    const int n = S.size();
    int prev = 0;
    for (int i = n - 1; i >= 0; --i) {
      shifts[i] = (shifts[i] % 26 + prev) % 26;
      prev = shifts[i];
    }
    for (int i = 0; i < n; i++) {
      S[i] = (S[i] - 'a' + shifts[i] ) % 26 + 'a';
    }
    return S;
  }
};
