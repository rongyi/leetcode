// https://leetcode.com/problems/naming-a-company/
#include "xxx.hpp"

class Solution {
public:
  long long distinctNames(vector<string> &ideas) {
    long long ret = 0;
    map<char, set<string>> groups;

    for (auto &w : ideas) {
      groups[w[0] - 'a'].insert(w.substr(1));
    }

    for (int i = 0; i < 25; ++i) {
      for (int j = i + 1; j < 26; ++j) {
        auto &s1 = groups[i];
        auto &s2 = groups[j];
        if (s1.empty() || s2.empty()) {
          continue;
        }
        int intersection_count = 0;
        for (auto &suff1 : s1) {
          if (s2.count(suff1)) {
            intersection_count += 1;
          }
        }
        ret += 2ll * (s1.size() - intersection_count) *
               (s2.size() - intersection_count);
      }
    }

    return ret;
  }
};
