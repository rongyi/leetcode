// http://leetcode.com/problems/group-anagrams/description/
#include "one.h"

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    unordered_map<string, vector<string>> dict;
    for (auto s : strs) {
      auto k = s;
      sort(k.begin(), k.end());
      dict[k].push_back(s);
    }
    vector<vector<string>> ret;
    for (auto kv : dict) {
      ret.push_back(kv.second);
    }
    return ret;
  }
};
