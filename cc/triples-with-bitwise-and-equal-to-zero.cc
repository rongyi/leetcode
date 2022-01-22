// http://leetcode.com/problems/triples-with-bitwise-and-equal-to-zero/description/
#include "xxx.hpp"

class Solution {
public:
  int countTriplets(vector<int> &A) {
    int tuples[1 << 16] = {};
    for (auto a : A) {
      for (auto b : A) {
        ++tuples[a & b];
      }
    }
    int ret = 0;
    for (auto a : A) {
      for (auto i = 0; i < (1 << 16); ++i) {
        if ((i & a) == 0) {
          ret += tuples[i];
        }
      }
    }
    return ret;
  }
};
