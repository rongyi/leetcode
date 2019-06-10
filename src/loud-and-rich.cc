// http://leetcode.com/problems/loud-and-rich/description/
#include "xxx.h"

class Solution {
public:
  vector<int> loudAndRich(vector<vector<int>> &richer, vector<int> &quiet) {
    const int n = quiet.size();
    unordered_map<int, vector<int>> rich_chain;

    for (auto &curp : richer) {
      rich_chain[curp[1]].push_back(curp[0]);
    }
    vector<int> ret(n, -1);
    for (int i = 0; i < n; i++) {
      dfs2(rich_chain, i, ret, quiet);
    }
    return ret;
  }

  int dfs2(unordered_map<int, vector<int>> &rich_chain, int cur,
           vector<int> &ret, vector<int> &quiet) {
    if (ret[cur] >= 0) {
      return ret[cur];
    }
    ret[cur] = cur;
    for (auto rich : rich_chain[cur]) {
      // 比他有钱的大佬还有比他更安静的，那就是他了
      if (quiet[ret[cur]] > quiet[dfs2(rich_chain, rich, ret, quiet)]) {
        ret[cur] = ret[rich];
      }
    }
    return ret[cur];
  }

  // TLE
  vector<int> loudAndRichTLE(vector<vector<int>> &richer, vector<int> &quiet) {
    const int n = quiet.size();

    vector<unordered_set<int>> richthan(n, unordered_set<int>{});
    unordered_map<int, vector<int>> rich_chain;

    for (auto &curp : richer) {
      rich_chain[curp[1]].push_back(curp[0]);
    }
    for (int i = 0; i < n; i++) {
      unordered_set<int> visited;
      dfs(rich_chain, visited, richthan, i, i);
    }
    vector<int> ret;
    for (int i = 0; i < n; i++) {
      auto cur_richer = richthan[i];
      auto cur_quiet = quiet[i];
      int min_quiet = cur_quiet;
      int min_quite_index = -1;
      for (auto r : cur_richer) {
        if (quiet[r] < min_quiet) {
          min_quiet = quiet[r];
          min_quite_index = r;
        }
      }
      if (min_quite_index == -1) {
        ret.push_back(i);
      } else {
        ret.push_back(min_quite_index);
      }
    }

    return ret;
  }

private:
  void dfs(unordered_map<int, vector<int>> &chain, unordered_set<int> &visited,
           vector<unordered_set<int>> &cache, int cur, int from) {
    if (visited.find(cur) != visited.end()) {
      return;
    }
    visited.insert(cur);
    // 比他有钱的大佬们
    for (auto richer : chain[cur]) {
      cache[cur].insert(richer);
      cache[from].insert(richer);
      dfs(chain, visited, cache, richer, from);
    }
  }
};

int main() {
  Solution so;
  vector<vector<int>> input1{
      {1, 0}, {2, 1}, {3, 1}, {3, 7}, {4, 3}, {5, 3}, {6, 3}};
  vector<int> input2{3, 2, 5, 4, 6, 1, 7, 0};
  so.loudAndRich(input1, input2);
}
