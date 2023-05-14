// http://leetcode.com/problems/maximum-product-of-word-lengths/description/
#include "xxx.hpp"

class Solution {
public:
  // key point: transform string to bit
  // so & operation can be used to check
  // wether there is some common value
  int maxProduct(vector<string> &words) {
    auto strbit = [](string &s) -> int {
      int ret = 0;
      // the char order in words isn't matter
      for (int i = 0; i < s.size(); i++) {
        ret |= (1 << (s[i] - 'a'));
      }

      return ret;
    };

    int sz = words.size();
    vector<int> wbits(sz, 0);
    for (int i = 0; i < sz; i++) {
      wbits[i] = strbit(words[i]);
    }

    int ret = 0;
    for (int i = 0; i < sz; i++) {
      for (int j = i + 1; j < sz; j++) {
        if ((wbits[i] & wbits[j]) == 0) {
          ret = max(ret, (int)words[i].size() * (int)words[j].size());
        }
      }
    }

    return ret;
  }
};

