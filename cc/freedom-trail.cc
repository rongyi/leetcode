// http://leetcode.com/problems/freedom-trail/description/
#include "xxx.hpp"

class Solution {
public:
  int findRotateSteps(string ring, string key) {
    const int m = ring.size();
    const int n = key.size();
    // 先记录下每一个字符所处的位置
    unordered_map<char, unordered_set<int>> index;
    for (int i = 0; i < m; i++) {
      index[ring[i]].insert(i);
    }

    // 表示12:00位置上的字符是当前ring上的某个位置时
    // 到key的某个位置时需要的步数
    vector<vector<int>> memo(m, vector<int>(n, 0));

    return dfs(ring, key, index, memo, 0, 0) + n;
  }

private:
  int dfs(string &ring, string &key,
          unordered_map<char, unordered_set<int>> &index,
          vector<vector<int>> &memo, int rpos, int kpos) {
    if (kpos == key.size()) {
      return 0;
    }
    if (memo[rpos][kpos]) {
      return memo[rpos][kpos];
    }
    int ret = numeric_limits<int>::max();

    // 当前12:00位置是ring[rpos], 从这个字符开始旋转key的kpos上的那个字符
    for (auto next_index : index[key[kpos]]) {
      // 这里计算 (i - j + ring_size) % ring_size 或者是 (j - i + ring_size) %
      // ring_size
      int diff = abs(next_index - rpos);
      int step = min(diff, (int)ring.size() - diff);

      // next_index 目前就是12:00 位置上的字符,然后寻找下一个字符
      ret = min(ret, dfs(ring, key, index, memo, next_index, kpos + 1) + step);
    }

    memo[rpos][kpos] = ret;

    return ret;
  }
};
