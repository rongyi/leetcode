// http://leetcode.com/problems/word-search-ii/description/
#include "xxx.hpp"

struct TrieNode {
  TrieNode *nodes_[26];
  bool is_leaf_;
  TrieNode() : is_leaf_(false) { memset(nodes_, 0, sizeof(nodes_)); }
};

class Solution {
public:
  vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
    addWords(words);

    int m = board.size();
    int n = board[0].size();

    set<string> uniq;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        dfs(board, m, n, i, j, "", uniq, &root_);
      }
    }

    vector<string> ret(uniq.begin(), uniq.end());
    return ret;
  }

private:
  void dfs(vector<vector<char>> &board, int m, int n, int x, int y, string cur,
           set<string> &uniq, TrieNode *trie_cur) {
    if (x < 0 || x >= m || y < 0 || y >= n || board[x][y] == ' ') {
      return;
    }
    char c = board[x][y];
    int idx = c - 'a';
    if (trie_cur->nodes_[idx] == nullptr) {
      return;
    }

    board[x][y] = ' ';

    cur += c;
    trie_cur = trie_cur->nodes_[idx];
    if (trie_cur->is_leaf_) {
      uniq.insert(cur);
    }
    // just like for (auto d = 0; d < 4; d++)
    dfs(board, m, n, x + 1, y, cur, uniq, trie_cur);
    dfs(board, m, n, x - 1, y, cur, uniq, trie_cur);
    dfs(board, m, n, x, y + 1, cur, uniq, trie_cur);
    dfs(board, m, n, x, y - 1, cur, uniq, trie_cur);

    board[x][y] = c;
  }
  void addWords(vector<string> &words) {
    for (auto &w : words) {
      addWord(w);
    }
  }
  void addWord(string &w) {
    TrieNode *cur = &root_;
    for (auto &c : w) {
      int idx = c - 'a';
      if (cur->nodes_[idx] == nullptr) {
        cur->nodes_[idx] = new TrieNode();
      }
      cur = cur->nodes_[idx];
    }
    // don't forget to seal!
    cur->is_leaf_ = true;
  }

private:
  TrieNode root_;
};
