// https://leetcode.com/problems/groups-of-strings/
#include "xxx.hpp"

class Solution {
public:
  vector<int> groupStrings(vector<string> &words) {
    // count each mask in words
    map<int, int> mask_count;
    for (auto &w : words) {
      int cur_mask = accumulate(w.begin(), w.end(), 0, [](int acc, char &cur) {
        return acc | (1 << (cur - 'a'));
      });
      ++mask_count[cur_mask];
    }
    // 1. delete/add one char: flip each bit one by one
    // 2. replacing char: flip two 10/01 bits two by two
    int groups = 0;
    int max_group_size = 0;
    while (!mask_count.empty()) {
      auto cur_sz = dfs(mask_count, begin(mask_count)->first);
      groups += (cur_sz > 0);
      max_group_size = max(max_group_size, cur_sz);
    }

    return {groups, max_group_size};
  }

private:
  int dfs(map<int, int> &m, int cur_mask) {
    int ret = 0;
    auto it = m.find(cur_mask);
    if (it != end(m)) {
      ret += it->second;
      m.erase(it);
      for (int i = 0; i < 26; ++i) {
        ret += dfs(m, cur_mask ^ (1 << i));
        for (int j = i + 1; j < 26; ++j) {
          if (((cur_mask >> i) & 1) != ((cur_mask >> j) & 1)) {
            ret += dfs(m, cur_mask ^ (1 << i) ^ (1 << j));
          }
        }
      }
    }

    return ret;
  }
};
