// https://leetcode.com/problems/solving-questions-with-brainpower/
#include "xxx.hpp"

class Solution {
public:
  long long mostPoints(vector<vector<int>> &questions) {
    int sz = questions.size();
    vector<long long> cache(sz, -1);

    return dfs(questions, 0, cache);
  }

private:
  // points, skip
  long long dfs(vector<vector<int>> &qs, int cur, vector<long long> &cache) {
    if (cur >= qs.size()) {
      return 0;
    }
    if (cache[cur] != -1) {
      return cache[cur];
    }
    // pick
    long long score1 = qs[cur][0];
    // ignore all those in [cur, cur + skip] included
    score1 += dfs(qs, cur + qs[cur][1] + 1, cache);

    // don't pick
    long long score2 = dfs(qs, cur + 1, cache);

    return cache[cur] = max(score1, score2);
  }
};
