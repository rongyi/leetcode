// http://leetcode.com/problems/decode-xored-permutation/description/
#include "xxx.hpp"

class Solution {
public:
  vector<int> decode(vector<int> &encoded) {
    // [a, b, c, d, e]
    // encoded ==> [a ^ b, b^c, c^d, d^e]
    // all ==> a ^ b ^ c ^ d^ e
    // all ^ (a ^b) ^ (c ^ d) ==> e
    const int n = encoded.size() + 1;
    int all = 0;
    for (int i = 1; i <= n; ++i) {
      all ^= i;
    }
    int eall = 0;
    for (int i = 0; i < n - 1; i += 2) {
      eall ^= encoded[i];
    }

    vector<int> ret{all ^ eall};
    for (int i = encoded.size() - 1; i >= 0; i--) {
      ret.push_back(ret.back() ^ encoded[i]);
    }
    reverse(ret.begin(), ret.end());

    return ret;
  }
};
