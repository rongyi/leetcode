// http://leetcode.com/problems/implement-trie-prefix-tree/description/
#include "xxx.hpp"

struct TrieNode {
  TrieNode *nodes_[26];
  bool is_leaf_;
  TrieNode() : is_leaf_(false) { memset(nodes_, 0, sizeof(nodes_)); }
};

class Trie {
public:
  Trie() { root_ = new TrieNode(); }

  void insert(string word) {
    TrieNode *cur = root_;
    for (auto &c : word) {
      int idx = c - 'a';
      if (cur->nodes_[idx] == nullptr) {
        cur->nodes_[idx] = new TrieNode();
      }
      cur = cur->nodes_[idx];
    }
    // like a seal, make it a flag for true
    cur->is_leaf_ = true;
  }

  bool search(string word) {
    TrieNode *cur = root_;
    for (auto &c : word) {
      int idx = c - 'a';
      if (cur->nodes_[idx] == nullptr) {
        return false;
      }
      cur = cur->nodes_[idx];
    }
    return cur->is_leaf_;
  }

  bool startsWith(string prefix) {
    TrieNode *cur = root_;
    for (auto &c : prefix) {
      int idx = c - 'a';
      if (cur->nodes_[idx] == nullptr) {
        return false;
      }
      cur = cur->nodes_[idx];
    }
    return true;
  }

private:
  TrieNode *root_;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
