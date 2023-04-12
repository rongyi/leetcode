// http://leetcode.com/problems/repeated-dna-sequences/description/
#include "xxx.hpp"

class Solution {
public:
  vector<string> findRepeatedDnaSequences(string s) {
    int sz = s.size();
    map<string, int> cnt;
    vector<string> ret;
    for (int i = 0; i + 10 <= sz; i++) {
      string cur = s.substr(i, 10);
      cnt[cur]++;
      if (cnt[cur] == 2) {
        ret.push_back(cur);
      }
    }

    return ret;
  }
};
