// http://leetcode.com/problems/number-of-equivalent-domino-pairs/description/
#include "xxx.h"

class Solution {
public:
  int numEquivDominoPairs(vector<vector<int>> &dominoes) {
    // 1 <= dominoes[i][j] <= 9
    // 平移到一个维度上
    unordered_map<int, int> count;
    int ret = 0;
    for (auto &domino : dominoes) {
      if (domino[0] <= domino[1]) {
        ret += count[domino[0] * 10 + domino[1]]++;
      } else {
        ret += count[domino[1] * 10 + domino[0]]++;
      }
    }

    return ret;
  }
};
