// http://leetcode.com/problems/minimum-index-sum-of-two-lists/description/
#include "xxx.hpp"

class Solution {
public:
  vector<string> findRestaurant(vector<string> &list1, vector<string> &list2) {
    unordered_map<string, int> index;
    for (int i = 0; i < list2.size(); i++) {
      index[list2[i]] = i;
    }
    unordered_map<int, vector<string>> common;
    for (int i = 0; i < list1.size(); i++) {
      if (index.find(list1[i]) != index.end()) {
        common[i + index[list1[i]]].push_back(list1[i]);
      }
    }
    int low_key = numeric_limits<int>::max();
    for (auto kv : common) {
      low_key = min(low_key, kv.first);
    }
    return common[low_key];
  }
};
