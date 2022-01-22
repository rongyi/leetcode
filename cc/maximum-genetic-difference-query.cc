// https://leetcode.com/problems/maximum-genetic-difference-query/
#include "xxx.hpp"

struct TrieNode {
  TrieNode *child_[2] = {};
  int mask_ = 0; // we don't delete, we use this mask to indicate
  // this bit is real or a junk bit, 1 real, 0 junk
  void increase(int number) {
    TrieNode *cur = this;
    for (int i = 17; i >= 0; --i) {
      int bit = (number >> i) & 1;
      if (cur->child_[bit] == nullptr) {
        cur->child_[bit] = new TrieNode();
      }
      cur = cur->child_[bit];
      cur->mask_++;
    }
  }

  void decrease(int number) {
    TrieNode *cur = this;
    for (int i = 17; i >= 0; --i) {
      int bit = (number >> i) & 1;
      cur = cur->child_[bit];
      cur->mask_--;
    }
  }
  int findMax(int number) {
    TrieNode *cur = this;
    int ret = 0;
    for (int i = 17; i >= 0; --i) {
      int bit = (number >> i) & 1;
      // xor operation, pick the diff road from MSB to LSB
      if (cur->child_[1 - bit] != nullptr && cur->child_[1 - bit]->mask_ > 0) {
        cur = cur->child_[1 - bit];
        ret |= (1 << i);
      } else {
        cur = cur->child_[bit];
      }
    }

    return ret;
  }
};

using pii = pair<int, int>;
class Solution {
public:
  vector<int> maxGeneticDifference(vector<int> &parents,
                                   vector<vector<int>> &queries) {
    int n = parents.size();
    int qsz = queries.size();
    int root = -1;
    vector<vector<int>> graph(n);
    for (int i = 0; i < n; ++i) {
      if (parents[i] == -1) {
        root = i;
      } else {
        // put current to parent child list
        graph[parents[i]].push_back(i);
      }
    }
    vector<vector<pii>> query_by_node(n);
    // queries [{node, val}...]
    // for n in node..root, find
    // max(n ^ val)
    for (int i = 0; i < qsz; ++i) {
      // attach the index
      query_by_node[queries[i][0]].push_back({queries[i][1], i});
    }
    vector<int> ret(qsz);
    dfs(root, graph, query_by_node, ret);

    return ret;
  }

private:
  void dfs(int cur, vector<vector<int>> &graph,
           vector<vector<pii>> &query_by_node, vector<int> &ret) {
    trie_root_.increase(cur);
    for (auto &p : query_by_node[cur]) {
      ret[p.second] = trie_root_.findMax(p.first);
    }
    for (int &v : graph[cur]) {
      dfs(v, graph, query_by_node, ret);
    }
    // to ensure a path from root to current
    trie_root_.decrease(cur);
  }

private:
  TrieNode trie_root_;
};
