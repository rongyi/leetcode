// http://leetcode.com/problems/largest-multiple-of-three/description/
#include "xxx.hpp"

class Solution {
public:
  // https://leetcode.com/problems/largest-multiple-of-three/discuss/518830/C%2B%2BJava-Concise-O(n)
  string largestMultipleOfThree(vector<int> &digits) {
    string ret;
    // 放在一起的想法很赞
    // 把余2穿插在这里
    int mo1[] = {1, 4, 7, 2, 5, 8};
    // 把余1穿插在这里
    int mo2[] = {2, 5, 8, 1, 4, 7};

    int sum = 0;
    int ds[10] = {};
    for (auto d : digits) {
      ++ds[d];
      sum += d;
    }

    while (sum % 3 != 0) {
      for (auto i : (sum % 3 == 1 ? mo1 : mo2)) {
        if (ds[i]) {
          --ds[i];
          sum -= i;
          break;
        }
      }
    }
    for (int i = 9; i >= 0; --i) {
      if (ds[i]) {
        ret += string(ds[i], '0' + i);
      }
    }
    if (ret.size() > 0 && ret[0] == '0') {
      return "0";
    }

    return ret;
  }
};
