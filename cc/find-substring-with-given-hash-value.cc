// https://leetcode.com/problems/find-substring-with-given-hash-value/
#include "xxx.hpp"

class Solution {
public:
  string subStrHash(string s, int power, int mod, int k, int hashValue) {
    // rolling hash
    auto val = [&](int idx) { return s[idx] - 'a' + 1; };
    long long cur_hash = 0;
    long long power_k = 1;
    long long ret = 0;
    // from right to left
    for (int i = s.size() - 1; i >= 0; --i) {
      // the last is rolling power every time to get p^(k - 1)
      cur_hash = (cur_hash * power + val(i)) % mod;
      if (i < s.size() - k) {
        cur_hash = (mod + cur_hash - power_k * val(i + k) % mod) % mod;
      } else {
        // Remove i + 1 - k character: subtract val(s[i + 1 - k]) * power ^ k
        // from hash
        power_k = power_k * power % mod;
      }
      if (cur_hash == hashValue) {
        ret = i;
      }
    }

    return s.substr(ret, k);
  }
};
