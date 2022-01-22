// http://leetcode.com/problems/uncommon-words-from-two-sentences/description/
#include "xxx.hpp"

class Solution {
public:
  vector<string> uncommonFromSentences(string A, string B) {
    auto gen = [](string &s) -> unordered_map<string, int> {
      unordered_map<string, int> ret;
      istringstream ss(s);
      string cur{};
      while (ss >> cur) {
        ret[cur]++;
      }
      return ret;
    };
    auto acnt = gen(A);
    auto bcnt = gen(B);
    vector<string> ret;
    for (auto kv : acnt) {
      if (kv.second == 1 && bcnt.find(kv.first) == bcnt.end()) {
        ret.push_back(kv.first);
      }
    }
    for (auto kv : bcnt) {
      if (kv.second == 1 && acnt.find(kv.first) == acnt.end()) {
        ret.push_back(kv.first);
      }
    }
    return ret;
  }
};
