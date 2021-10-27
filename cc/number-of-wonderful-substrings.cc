// http://leetcode.com/problems/number-of-wonderful-substrings/description/
#include "xxx.h"

class Solution {
public:
  // https://leetcode.com/problems/number-of-wonderful-substrings/discuss/1299773/Intuitive-explanation-easy-to-understand
  long long wonderfulSubstrings(string word) {
    vector<long long> count(1024, 0);
    // all char occur even
    count[0] = 1;

    long long cur_mask = 0;
    long long ret = 0;
    for (auto &c : word) {
      int idx = c - 'a';
      cur_mask ^= (1 << idx);
      ret += count[cur_mask];
      // why a loop?
      // e.g aaaba
      // in this case for loop make b desappear and make a valid substring
      for (int i = 0; i < 10; ++i) {
        int prev = cur_mask ^ (1 << i);
        ret += count[prev];
      }

      count[cur_mask]++;
    }

    return ret;
  }
};
