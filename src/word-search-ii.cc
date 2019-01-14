// http://leetcode.com/problems/word-search-ii/description/
#include "xxx.h"

// from file: ./implement-trie.cc
namespace detail {
struct TrieNode {
  static const int NUM = 26;
  TrieNode() : is_leaf_(false) { std::memset(node_, 0, sizeof(node_)); }

  bool HasNoChild() const {
    for (auto p : node_) {
      if (p)
        return false;
    }
    return true;
  }

  bool is_leaf_;
  TrieNode *node_[NUM];
};

class Trie {
public:
  Trie() { root = new TrieNode(); }

  // Inserts a word into the trie.
  void insert(string word) {
    if (word.empty())
      return;

    TrieNode *p = root;
    for (auto c : word) {
      if (!p->node_[std::tolower(c) - 'a'])
        p->node_[std::tolower(c) - 'a'] = new TrieNode();
      p = p->node_[std::tolower(c) - 'a'];
    }
    p->is_leaf_ = true;
  }

  // Returns if the word is in the trie.
  bool contains(string word) {
    if (word.empty())
      return false;
    return search(word, root, 0);
  }

  // Returns if there is any word in the trie
  // that starts with the given prefix.
  bool startsWith(string prefix) {
    if (prefix.empty())
      return false;
    return start(prefix, root, 0);
  }

  bool search(const string &word, TrieNode *root, unsigned level) {
    if (level == word.size())
      return root->is_leaf_;
    const char cur = std::tolower(word[level]);
    return root->node_[cur - 'a'] &&
           search(word, root->node_[cur - 'a'], level + 1);
  }
  bool start(const string &word, TrieNode *root, unsigned level) {
    if (level == word.size())
      return root != nullptr;
    const char cur = std::tolower(word[level]);
    return root->node_[cur - 'a'] &&
           start(word, root->node_[cur - 'a'], level + 1);
  }

  ~Trie() { do_delete(root); }

private:
  void do_delete(TrieNode *root) {
    if (!root)
      return;
    for (auto p : root->node_) {
      if (p) {
        do_delete(p);
        p = nullptr;
      }
    }

    if (root->HasNoChild()) {
      delete root;
      root = nullptr;
    }
  }
  TrieNode *root;
};
} // namespace detail

class Solution {
public:
  vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {

    vector<string> ret;
    if (board.empty() || board[0].empty() || words.empty())
      return ret;

    m_ = board.size();
    n_ = board[0].size();
    directions_ = vector<vector<int>>{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    // uniq ret
    unordered_set<string> uniq_word;

    for (auto &w : words) {
      trie_.insert(w);
    }

    // the A.I part
    vector<vector<bool>> visited(m_, vector<bool>(n_, false));

    string s;
    for (int i = 0; i < m_; i++) {
      for (int j = 0; j < n_; j++) {
        s.push_back(board[i][j]);
        if (trie_.contains(s))
          uniq_word.insert(s);
        if (trie_.startsWith(s))
          search(board, s, i, j, visited, uniq_word);
        s.pop_back();
      }
    }
    for (auto &w : uniq_word)
      ret.push_back(w);
    return ret;
  }

  void search(const vector<vector<char>> &board, string &word, int i, int j,
              vector<vector<bool>> &visited, unordered_set<string> &uniq_word) {

    auto isBoundaryValid = [](int cur_row, int cur_col,
                              vector<vector<bool>> &visited, int m, int n) {
      if (cur_row < 0 || cur_col < 0 || cur_row == m || cur_col == n ||
          visited[cur_row][cur_col] == true) {
        return false;
      }
      return true;
    };

    // mark as visited
    visited[i][j] = true;

    for (int d = 0; d < 4; d++) {
      auto next_x = i + directions_[d][0];
      auto next_y = j + directions_[d][1];
      if (isBoundaryValid(next_x, next_y, visited, m_, n_)) {
        word.push_back(board[next_x][next_y]);
        if (trie_.contains(word))
          uniq_word.insert(word);
        if (trie_.startsWith(word))
          search(board, word, next_x, next_y, visited, uniq_word);
        word.pop_back();
      }
    }

    // mark it back
    visited[i][j] = false;
  }

private:
  detail::Trie trie_;
  vector<vector<int>> directions_;
  int m_;
  int n_;
};

int main() {
  Solution so;
  vector<char> row1{'a', 'b', 'c', 'e'};
  vector<char> row2{'s', 'f', 'c', 's'};
  vector<char> row3{'a', 'd', 'e', 'e'};
  vector<vector<char>> test{row1, row2, row3};
  vector<string> words{"as", "ab", "cf", "da", "ee", "e", "adee", "eeda"};

  auto ret = so.findWords(test, words);
  for (auto s : ret)
    cout << s << endl;

  return 0;
}
