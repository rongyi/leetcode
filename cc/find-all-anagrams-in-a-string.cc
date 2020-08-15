// http://leetcode.com/problems/find-all-anagrams-in-a-string/description/
#include "xxx.h"

class Solution {
public:
  vector<int> findAnagrams(string s, string p) {
    vector<int> ret;
    // sort(p.begin(), p.end());
    const int m = s.size();
    const int n = p.size();
    // using unordered_map tle?
    vector<int> pmap(128, 0);

    for (auto c : p) {
      ++pmap[c];
    }

    for (int i = 0; i < m; ++i) {
      bool succ = true;
      auto cp = pmap;

      for (int j = i; j < i + n; ++j) {
        if (--cp[s[j]] < 0) {
          succ = false;
          break;
        }
      }

      if (succ) {
        ret.push_back(i);
      }
    }
    return ret;
  }
};
