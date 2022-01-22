// http://leetcode.com/problems/circular-permutation-in-binary-representation/description/
#include "xxx.hpp"

class Solution {
public:
  // 喷的很厉害
  vector<int> circularPermutation(int n, int start) {
    vector<int> ret;
    for (int i = 0; i < (1 << n); ++i) {
      ret.push_back(start ^ i ^ i >> 1);
    }

    return ret;
  }
};
