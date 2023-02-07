// http://leetcode.com/problems/substring-with-concatenation-of-all-words/description/
#include "xxx.hpp"
class Solution {
public:
  vector<int> findSubstring(string s, vector<string> &words) {
    int sz = s.size();
    int blocks = words.size();
    int wsz = words[0].size();
    int chunksz = blocks * wsz;
    map<string, int> cnt;
    for (auto &p : words) {
      cnt[p]++;
    }

    vector<int> ret;
    for (int i = 0; i + chunksz - 1 < sz; i++) {
      // current blocks
      int j = 0;
      map<string, int> cur_cnt;
      for (; j < blocks; ++j) {
        string cur = s.substr(i + j * wsz, wsz);
        if (!cnt[cur]) {
          break;
        }
        cur_cnt[cur]++;
        // too much
        if (cur_cnt[cur] > cnt[cur]) {
          break;
        }
      }
      if (j == blocks) {
        ret.push_back(i);
      }
    }
    return ret;
  }
};
