// http://leetcode.com/problems/pancake-sorting/description/
#include "xxx.hpp"

class Solution {
public:
  vector<int> pancakeSort(vector<int> &A) {
    vector<int> ret;
    for (int i = 0; i < A.size(); i++) {

      auto maxpos = max_element(A.begin(), A.end() - i);
      ret.push_back(maxpos - A.begin() + 1);
      ret.push_back(A.size() - i);

      // 先把最大的翻最上面去
      reverse(A.begin(), maxpos + 1);
      // 这一次翻转，目的就是把当前最大的给它归位
      reverse(A.begin(), A.end() - i);
    }

    return ret;
  }
};
