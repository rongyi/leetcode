// https://leetcode.com/problems/destination-city/
#include "xxx.hpp"

class Solution {
public:
  string destCity(vector<vector<string>> &paths) {
    unordered_map<string, vector<string>> count;
    unordered_set<string> cits;
    for (auto &p : paths) {
      count[p[0]].push_back(p[1]);
      cits.insert(p[0]);
      cits.insert(p[1]);
    }

    for (auto &c : cits) {
      if (count.find(c) == count.end()) {
        return c;
      }
    }

    return "";
  }
};
