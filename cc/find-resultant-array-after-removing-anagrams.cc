// https://leetcode.com/problems/find-resultant-array-after-removing-anagrams/
#include "xxx.hpp"

class Solution {
public:
  vector<string> removeAnagrams(vector<string> &words) {
    int sz = words.size();
    vector<string> sw;
    for (int i = 0; i < sz; ++i) {
      string cp = words[i];
      sort(cp.begin(), cp.end());
      sw.push_back(cp);
    }
    vector<string> ret{words[0]};

    for (int i = 1; i < sz; ++i) {
      if (sw[i] == sw[i - 1]) {
        continue;
      }
      ret.push_back(words[i]);
    }

    return ret;
  }
};
