// http://leetcode.com/problems/queries-on-a-permutation-with-key/description/
#include "xxx.h"

// 喷的很惨
class Solution {
public:
  vector<int> processQueries(vector<int> &queries, int m) {
    vector<int> ret;
    vector<int> idx;
    for (int i = 0; i < m; ++i) {
      idx.push_back(i);
    }
    for (int i = 0; i < queries.size(); ++i) {
      auto cur = idx[queries[i] - 1];
      ret.push_back(cur);
      // 模拟排在前面的过程，比当前indx值小的位置统统都相应往后移，之后的index保持不动
      for (int j = 0; j < m; ++j) {
        if (idx[j] < cur) {
          idx[j] += 1;
        }
      }
      // 当前的拎到最前面
      idx[queries[i] - 1] = 0;
    }

    return ret;
  }
};
