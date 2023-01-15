// https://leetcode.com/problems/partition-string-into-substrings-with-values-at-most-k/
#include "xxx.hpp"

class Solution {
public:
  int minimumPartition(string s, int k) {
    int sz = s.size();
    int cut = 0;

    long long acc = 0;
    for (int i = 0; i < sz; ++i) {
      int d = (s[i] - '0');
      if (d > k) {
        return -1;
      }
      acc *= 10;
      acc += d;
      if (acc > k) {
        cut++;
        acc = d;
      }
    }

    return cut + 1;
  }
};
