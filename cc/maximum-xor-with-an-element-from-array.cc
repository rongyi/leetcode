// http://leetcode.com/problems/maximum-xor-with-an-element-from-array/description/
#include "xxx.h"

class Solution {
private:
  struct TrieNode {
    TrieNode *next[2];
    TrieNode() {
      next[0] = nullptr;
      next[1] = nullptr;
    }
  };

public:
  vector<int> maximizeXor(vector<int> &nums, vector<vector<int>> &queries) {
    vector<int> ret;
    auto root = buildTrie(nums);
    for (auto &q : queries) {
      auto cur = dfs(root, q[0], q[1], 0, 30);

      ret.push_back(cur);
    }

    return ret;
  }

private:
  TrieNode *buildTrie(vector<int> &nums) {
    TrieNode *root = new TrieNode();
    TrieNode *cur = nullptr;
    for (auto &num : nums) {
      // ensure from top root
      cur = root;
      // 都是大杂烩混在一起了
      for (int i = 30; i >= 0; i--) {
        auto x = (num >> i) & 1;
        if (cur->next[x] == nullptr) {
          cur->next[x] = new TrieNode();
        }
        cur = cur->next[x];
      }
    }

    return root;
  }
  // 当前位cur来进行查询的区分
  int dfs(TrieNode *root, int x, int limit, int cur, int height) {
    if (cur > limit) {
      return -1;
    }
    if (height == -1) {
      return cur ^ x;
    }
    int curbit = (x >> height) & 1;

    // 保证xor最大就优先走不一样的路
    if (root->next[1 - curbit]) {
      auto ret = dfs(root->next[1 - curbit], x, limit,
                     cur | ((1 - curbit) << height), height - 1);
      if (ret >= 0) {
        return ret;
      }
    }

    if (root->next[curbit]) {
      auto ret = dfs(root->next[curbit], x, limit, cur | (curbit << height),
                     height - 1);
      if (ret >= 0) {
        return ret;
      }
    }

    return -1;
  }
};
