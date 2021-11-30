// https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/
#include "xxx.h"

class Solution {
public:
  int minSwaps(string s) {
    int balance = 0;
    int total_swap = 0;
    int sz = s.size();
    int j = sz - 1;
    for (int i = 0; i < sz; ++i) {
      if (s[i] == '[') {
        balance++;
      } else {
        balance--;
      }
      // means we met a ] first, but it's [ is after him
      if (balance < 0) {
        // find the match from last
        while (j > i && s[j] != '[') {
          --j;
        }
        // now j stop at the valid [
        swap(s[i], s[j]);
        total_swap++;
        // reset balance to 1, because we met a [ at first
        balance = 1;
      }
    }

    return total_swap;
  }
};
