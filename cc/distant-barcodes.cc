// http://leetcode.com/problems/distant-barcodes/description/
#include "xxx.h"

class Solution {
public:
  vector<int> rearrangeBarcodes(vector<int> &barcodes) {
    const int n = barcodes.size();
    unordered_map<int, int> counts;
    for (auto cur_bar : barcodes) {
      ++counts[cur_bar];
    }
    set<pair<int, int>> s;
    for (auto kv : counts) {
      // 用出现次数作为key
      s.insert({kv.second, kv.first});
    }

    int pos = 0;
    for (auto it = s.rbegin(); it != s.rend(); ++it) {
      int cur_count = it->first;
      int num = it->second;
      for (int i = 0; i < cur_count; ++i, pos += 2) {
        if (pos >= n) {
          pos = 1;
        }
        barcodes[pos] = num;
      }
    }
    return barcodes;
  }
};
