// http://leetcode.com/problems/sort-characters-by-frequency/description/
#include "xxx.h"

class Solution {
public:
  string frequencySort(string s) {
    // char --> count
    unordered_map<char, int> count;
    for (auto c : s) {
      count[c]++;
    }
    unordered_map<int, unordered_set<char>> group;
    for (auto kv : count) {
      group[kv.second].insert(kv.first);
    }

    vector<int> nums;
    for (auto kv : group) {
      nums.push_back(kv.first);
    }
    sort(nums.begin(), nums.end(), greater<int>());
    stringstream ss;
    for (auto num : nums) {
      auto chars = group[num];
      for (auto c : chars) {
        for (int i = 0; i < num; i++) {
          ss << c;
        }
      }
    }
    return ss.str();
  }
};
