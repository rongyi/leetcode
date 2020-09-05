// http://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/description/
#include "xxx.h"

class Solution {
public:
  bool hasAllCodes(string s, int k) {
    // TLE version
    // for (int i = 0; i < (1 << k); ++i) {
    //   auto cur = bitset<32>(i).to_string();
    //   cur = cur.substr(32 - k);
    //   if (s.find(cur) == string::npos) {
    //     return false;
    //   }
    // }
    // return true;

    int cur_num = 0;
    int mask = (1 << k) - 1;
    int cur_count = 0;
    vector<bool> found(1 << k, false);
    for (int i = 0; i < s.size(); ++i) {
      cur_num = mask & ((cur_num << 1) + s[i] - '0');
      if (i >= k - 1) {
        if (found[cur_num] == false) {
          cur_count++;
        }
        found[cur_num] = true;
      }
    }

    return cur_count == found.size();
  }
};
