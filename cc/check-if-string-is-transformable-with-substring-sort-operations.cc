#include "xxx.hpp"

class Solution {
public:
  bool isTransformable(string s, string t) {
    // 标记源字符的index
    vector<vector<int>> idx(10);
    // 统计使用情况
    vector<int> pos(10, 0);
    for (int i = 0; i < s.size(); ++i) {
      idx[s[i] - '0'].push_back(i);
    }
    // 从t一个个开始恢复
    for (auto ch : t) {
      int d = ch - '0';
      // 所以字符在源中都安排妥当，结果又遇到一个，那显然是多的
      if (pos[d] >= idx[d].size()) {
        return false;
      }

      for (int i = 0; i < d; ++i) {
        // 要求是待安排的字符在源字符串里前面不能有比它小的，如果有就安排不了
        // e.g. s: 12345
        //      t: 12435
        // 安排到4的时候没办法了,因为选择大于2的任意包含4的子字符串，3总归是要在4前面的，这个是核心
        if (pos[i] < idx[i].size() && idx[i][pos[i]] < idx[d][pos[d]]) {
          return false;
        }
      }
      ++pos[d];
    }
    return true;
  }
};
