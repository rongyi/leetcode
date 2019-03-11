// http://leetcode.com/problems/freedom-trail/description/
#include "xxx.h"

class Solution {
public:
  int findRotateSteps(string ring, string key) {
    const int m = ring.size();
    const int n = key.size();
    unordered_map<char, unordered_set<int>> index;
    for (int i = 0; i < m; i++) {
      index[ring[i]].insert(i);
    }

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

    for (auto next_index : index[key[kpos]]) {
      int diff = abs(next_index - rpos);
      int step = min(diff, (int)ring.size() - diff);
      ret = min(ret, dfs(ring, key, index, memo, next_index, kpos + 1) + step);
    }

    memo[rpos][kpos] = ret;

    return ret;
  }
};
