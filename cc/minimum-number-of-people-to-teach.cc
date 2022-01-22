// http://leetcode.com/problems/minimum-number-of-people-to-teach/description/
#include "xxx.hpp"

class Solution {
public:
  // 喷的很惨
  int minimumTeachings(int n, vector<vector<int>> &languages,
                       vector<vector<int>> &friendships) {
    // 有这么多人
    const int m = languages.size();
    // 每个哥们会的语言集合
    vector<unordered_set<int>> langs;
    for (int i = 0; i < languages.size(); ++i) {
      auto s = unordered_set<int>(languages[i].begin(), languages[i].end());
      langs.push_back(s);
    }
    int ret = m;
    vector<vector<int>> cache(m + 1, vector<int>(m + 1, 0));

    // If the two friends can already communicate via a common language, ignore
    // and move to next friendship
    // Otherwise, teach them the language (assuming they don't know it already)
    // Find the minimum number of friends to teach for any language
    for (int l = 1; l <= n; ++l) {
      int cur_count = 0;
      vector<bool> teach(m, false);
      for (int i = 0; i < friendships.size(); ++i) {
        int u = friendships[i][0] - 1;
        int v = friendships[i][1] - 1;
        if (haveCommonLang(cache, langs, u, v)) {
          continue;
        }
        if (langs[u].find(l) == langs[u].end()) {
          if (!teach[u]) {
            cur_count++;
          }
          teach[u] = true;
        }

        if (langs[v].find(l) == langs[v].end()) {
          if (!teach[v]) {
            cur_count++;
          }
          teach[v] = true;
        }
      }
      ret = min(ret, cur_count);
    }

    return ret;
  }

private:
  // 不加cache会超时
  bool haveCommonLang(vector<vector<int>> &cache,
                      vector<unordered_set<int>> &langs, int u, int v) {
    if (cache[u][v] != 0) {
      return cache[u][v] == 1;
    }
    for (auto l : langs[u]) {
      if (langs[v].find(l) != langs[v].end()) {
        cache[u][v] = 1;
        return true;
      }
    }
    cache[u][v] = -1;
    return false;
  }
};
