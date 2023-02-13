// http://leetcode.com/problems/group-anagrams/description/
#include "xxx.hpp"

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    map<string, vector<string>> group;
    for (auto &w : strs) {
      string k = w;
      sort(k.begin(), k.end());
      group[k].push_back(w);
    }
    vector<vector<string>> ret;
    for (auto &kv : group) {
      ret.push_back(kv.second);
    }

    return ret;
  }
};
