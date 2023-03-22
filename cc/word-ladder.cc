// http://leetcode.com/problems/word-ladder/description/
#include "xxx.hpp"

class Solution {
public:
  int ladderLength(string w1, string w2, vector<string> &dict) {
    set<string> words(dict.begin(), dict.end());
    // end no in dict
    if (!words.count(w2)) {
      return 0;
    }
    // {w, depth}
    queue<pair<string, int>> q;
    q.push({w1, 1});

    while (!q.empty()) {
      auto cur = q.front();
      q.pop();
      if (cur.first == w2) {
        return cur.second;
      }
      auto neibs = collect(cur.first, words);
      for (auto &n : neibs) {
        q.push({n, cur.second + 1});
      }
    }

    return 0;
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
};
