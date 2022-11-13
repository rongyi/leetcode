// https://leetcode.com/problems/find-the-original-array-of-prefix-xor/
#include "xxx.hpp"

class Solution {
public:
  vector<int> findArray(vector<int> &pref) {
    int sz = pref.size();
    vector<int> ret(sz, 0);
    ret[0] = pref[0];

    for (int i = 1; i < sz; ++i) {
      ret[i] = pref[i] ^ pref[i - 1];
    }

    return ret;
  }
};
