// http://leetcode.com/problems/bulls-and-cows/description/
#include "simpleone.h"

class Solution {
public:
  string getHint(string secret, string guess) {
    unordered_map<char, int> gset;
    int exactly = 0;
    int misorder = 0;
    unordered_map<char, int> sset;
    // 1123
    // 0111
    // 找先对齐的，没有对齐的计算统计数字
    for (int i = 0; i < secret.size(); i++) {
      if (secret[i] == guess[i]) {
        exactly++;
      } else {
        gset[secret[i]]++;
        sset[guess[i]]++;
      }
    }

    for (auto kv : sset) {
      if (gset.find(kv.first) != gset.end()) {
        misorder += min(kv.second, gset[kv.first]);
      }
    }

    return to_string(exactly) + "A" + to_string(misorder) + "B";
  }
};
