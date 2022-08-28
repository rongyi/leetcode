// https://leetcode.com/problems/merge-similar-items/
#include "xxx.hpp"

class Solution {
public:
  vector<vector<int>> mergeSimilarItems(vector<vector<int>> &items1,
      vector<vector<int>> &items2) {
    map<int, int> value_to_wsum;
    for (auto &item : items1) {
      value_to_wsum[item[0]] += item[1];
    }
    for (auto &item : items2) {
      value_to_wsum[item[0]] += item[1];
    }
    vector<vector<int>> ret;
    for (auto &kv: value_to_wsum) {
      ret.push_back({kv.first, kv.second});
    }

    return ret;
  }
};
