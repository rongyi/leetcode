// http://leetcode.com/problems/word-ladder-ii/description/
#include "xxx.hpp"

class Solution {
public:
  vector<vector<string>> findLadders(string w1, string w2,
                                     vector<string> &dict) {
    set<string> words(dict.begin(), dict.end());

    queue<string> q;
    q.push(w1);

    map<string, int> depth_cache;
    depth_cache[w1] = 1;

    while (!q.empty()) {
      auto cur = q.front();
      q.pop();
      for (auto &n : collect(cur, words)) {
        q.push(n);
        if (!depth_cache.count(n)) {
          depth_cache[n] = depth_cache[cur] + 1;
        }
      }
    }
    vector<vector<string>> ret;
    if (depth_cache.count(w2)) {
      dfs(w1, w2, depth_cache, ret, {});
    }
    return ret;
  }

private:
  vector<string> collect(string s, set<string> &dict) {
    vector<string> ret;
    for (int i = 0; i < s.size(); i++) {
      string cp = s;
      for (int j = 0; j < 26; j++) {
        if (cp[i] == 'a' + j) {
          continue;
        }
        cp[i] = 'a' + j;
        if (dict.count(cp)) {
          ret.push_back(cp);
          dict.erase(cp);
        }
      }
    }

    return ret;
  }
  void dfs(string &w1, string cur_end, map<string, int> &dc,
           vector<vector<string>> &ret, vector<string> curpath) {
    curpath.push_back(cur_end);
    if (cur_end == w1) {
      reverse(curpath.begin(), curpath.end());
      ret.push_back(curpath);
      return;
    }
    int d = dc[cur_end];

    for (int i = 0; i < w1.size(); i++) {
      string cp = cur_end;
      for (int j = 0; j < 26; j++) {
        cp[i] = 'a' + j;
        if (dc.count(cp) && dc[cp] == d - 1) {
          dfs(w1, cp, dc, ret, curpath);
        }
      }
    }
  }
};
