// http://leetcode.com/problems/rank-transform-of-an-array/description/
#include "xxx.h"

class Solution {
public:
  vector<int> arrayRankTransform(vector<int> &arr) {
    set<int> rank;
    for (auto &num : arr) {
      rank.insert(num);
    }
    int rank_index = 1;
    unordered_map<int, int> index;
    for (auto &num : rank) {
      index[num] = rank_index++;
    }
    vector<int> ret;
    for (auto &num : arr) {
      ret.push_back(index[num]);
    }

    return ret;
  }
};
