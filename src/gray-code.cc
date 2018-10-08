// http://leetcode.com/problems/gray-code/description/
#include "one.h"

class Solution {
public:
  // 这题也是被喷的一塌糊涂
  vector<int> grayCode(int n) {
    vector<int> ret;

    const unsigned size = 1 << n;
    ret.reserve(size);
    for (unsigned i = 0; i < size; ++i) {
      ret.push_back(binary_to_gray(i));
    }

    return ret;
  }

private:
  unsigned int binary_to_gray(unsigned int n) { return n ^ (n >> 1); }
};
