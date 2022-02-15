// https://leetcode.com/problems/valid-arrangement-of-pairs/
#include "xxx.hpp"

class Solution {
public:
  // rearrange to makesure [a, b] [c, d] ==> (b == c) (last end == next start)
  vector<vector<int>> validArrangement(vector<vector<int>> &pairs) {
    unordered_multimap<int, int> m;
    unordered_map<int, int> cnt;
    vector<vector<int>> ret;
    for (auto &p : pairs) {
      m.insert({p[0], p[1]});
      // out degree+
      ++cnt[p[0]];
      --cnt[p[1]];
      // in degree-
      // so the header is degree > 0
      // see below find lambda
    }
    auto head = find_if(cnt.begin(), cnt.end(),
                        [&](const auto &p) { return p.second > 0; });
    if (head != cnt.end()) {
      dfs(head->first, m, ret);
    } else {
      // whatever start node
      dfs(pairs[0][0], m, ret);
    }

    reverse(ret.begin(), ret.end());
    return ret;
  }

private:
  void dfs(int from, unordered_multimap<int, int> &m,
           vector<vector<int>> &ret) {
    auto it = m.find(from);
    while (it != end(m)) {
      auto to = it->second;
      m.erase(it);
      dfs(to, m, ret);
      ret.push_back({from, to});
      it = m.find(from);
    }
  }
};
