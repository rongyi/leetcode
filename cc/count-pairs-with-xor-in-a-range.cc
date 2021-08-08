// http://leetcode.com/problems/count-pairs-with-xor-in-a-range/description/
#include_next "xxx.h"

class Solution {
public:
  struct TrieNode {
    int count_ = 0;
    array<TrieNode *, 2> children_{nullptr, nullptr};
  };

  int countPairs(vector<int> &nums, int low, int high) {
    int ret = 0;
    TrieNode root;
    auto Add = [&](int n) {
      auto *p = &root;
      for (int sh = 14; sh >= 0; --sh) {
        int bit = (n & (1 << sh)) != 0;
        if (!p->children_[bit]) {
          p->children_[bit] = new TrieNode;
        }
        p = p->children_[bit];
        ++(p->count_);
      }
    };
    auto Count = [&](int n, int limit) {
      int ret = 0;
      int m = (1 << 14);
      for (auto *p = &root; p && m; m >>= 1) {
        int cur_bit_of_n = n & m;
        int cur_bit_of_limit = limit & m;
        // limit当前位为0，那么我们取当前位和num不一样的，那么xor
        // 起来肯定为1，也就是肯定大于limit了
        if (!cur_bit_of_limit && p->children_[!cur_bit_of_n]) {
          ret += p->children_[!cur_bit_of_n]->count_;
        }
        p = p->children_[(cur_bit_of_n ^ cur_bit_of_limit) != 0];
      }
      return ret;
    };
    for (auto n : nums) {
      ret += Count(n, low - 1) - Count(n, high);
      Add(n);
    }

    return ret;
  }
};
