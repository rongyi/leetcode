// https://leetcode.com/problems/sum-of-prefix-scores-of-strings/
#include "xxx.hpp"

struct Trie {
  Trie *entry_[26] = {};
  int count_ = 0;

  void insert(string &s) {
    auto cur = this;
    for (auto &c : s) {
      if (cur->entry_[c - 'a'] == nullptr) {
        cur->entry_[c - 'a'] = new Trie();
      }
      cur = cur->entry_[c - 'a'];
      ++cur->count_;
    }
  }
  int count(string &s, int pos) {
    if (pos >= s.size()) {
      return count_;
    }

    return count_ + entry_[s[pos] - 'a']->count(s, pos + 1);
  }
};

class Solution {
public:
  vector<int> sumPrefixScores(vector<string> &words) {
    Trie t;
    for (auto &w : words) {
      t.insert(w);
    }
    vector<int> ret;
    for (auto &w : words) {
      ret.push_back(t.count(w, 0));
    }
    return ret;
  }
};
