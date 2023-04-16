// https://leetcode.com/problems/design-add-and-search-words-data-structure/
#include "xxx.hpp"

struct TrieNode {
  TrieNode *nodes_[26];
  bool is_leaf_;
  TrieNode() : is_leaf_(false) { memset(nodes_, 0, sizeof(nodes_)); }
};

class WordDictionary {
public:
  WordDictionary() {}

  void addWord(string word) {
    TrieNode *cur = &root_;
    for (auto &c : word) {
      int idx = c - 'a';
      if (cur->nodes_[idx] == nullptr) {
        cur->nodes_[idx] = new TrieNode();
      }
      cur = cur->nodes_[idx];
    }
    cur->is_leaf_ = true;
  }

  bool search(string word) { return searchafter(&root_, word); }

private:
  bool searchafter(TrieNode *cur, string word) {
    // no way for this branch
    if (cur == nullptr) {
      return false;
    }
    for (int i = 0; i < word.size(); i++) {
      if (word[i] == '.') {
        string w = word.substr(i + 1);
        for (int j = 0; j < 26; j++) {
          if (searchafter(cur->nodes_[j], w)) {
            return true;
          }
        }
        // try all case and fail, we should go
        return false;
      } else {
        // normal compare
        int idx = word[i] - 'a';
        if (cur->nodes_[idx] == nullptr) {
          return false;
        }
        cur = cur->nodes_[idx];
      }
    }

    return cur->is_leaf_;
  }

private:
  TrieNode root_;
};
