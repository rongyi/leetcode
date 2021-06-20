// http://leetcode.com/problems/decode-xored-array/description/
#include "xxx.h"

class Solution {
public:
  vector<int> decode(vector<int> &encoded, int first) {
    vector<int> ret{first};
    for (auto &e : encoded) {
      first ^= e;
      ret.push_back(first);
    }

    return ret;
  }
};
