// https://leetcode.com/problems/neighboring-bitwise-xor/
#include "xxx.hpp"

class Solution {
public:
  bool doesValidArrayExist(vector<int> &derived) {
    int sz = derived.size();

    int i = 0;
    // case 1: first is zero in origin array
    int origin_zero = 0;
    // case 2: first is one
    int origin_one = 1;


    // origin:
    // 1 (1 ^ 0)
    // derived:
    // 0 1 0
    // the next in origin is current origin ^ current derived
    // we want to get the last one, so don't calulate the last derived
    for (; i < sz - 1; i++) {
      origin_zero ^= derived[i];
      origin_one ^= derived[i];
    }
    if ((origin_zero ^ 0) == derived[sz - 1]) {
      return true;
    }
    if ((origin_one ^ 1) == derived[sz - 1]) {
      return true;
    }

    return false;
  }
};

int main() {
  Solution so;
  vector<int> input{1, 0};
  so.doesValidArrayExist(input);
}
