// http://leetcode.com/problems/reconstruct-a-2-row-binary-matrix/description/
#include "xxx.hpp"

class Solution {
public:
  vector<vector<int>> reconstructMatrix(int upper, int lower,
                                        vector<int> &colsum) {
    vector<vector<int>> ret(2, vector<int>(colsum.size(), 0));
    vector<int> alter_index{};
    for (int i = 0; i < colsum.size(); ++i) {
      if (colsum[i] == 2) {
        ret[0][i] = 1;
        ret[1][i] = 1;
        --upper;
        --lower;
        // 有2的情况就已经给它撑爆了
        if (upper < 0 || lower < 0) {
          return {};
        }
      } else if (colsum[i] == 1) {
        alter_index.push_back(i);
      }
    }
    if ((upper + lower) != alter_index.size()) {
      return {};
    }
    // 就这么分吧，前面给上面，后面给下面
    for (int i = 0; i < upper; ++i) {
      ret[0][alter_index[i]] = 1;
    }
    for (int i = upper; i < alter_index.size(); ++i) {
      ret[1][alter_index[i]] = 1;
    }

    return ret;
  }
};

int main() {
  Solution so;
  vector<int> input{0, 1, 2, 0, 0, 0, 0, 0, 2, 1, 2, 1, 2};
  // 9
  // 2
  // [0,1,2,0,0,0,0,0,2,1,2,1,2]
  so.reconstructMatrix(9, 2, input);
}
