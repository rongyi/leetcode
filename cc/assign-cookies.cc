// http://leetcode.com/problems/assign-cookies/description/
#include "xxx.h"

class Solution {
public:
  int findContentChildren(vector<int> &g, vector<int> &s) {
    unordered_map<int, int> ckcount;
    for (auto i : s) {
      ckcount[i]++;
    }
    vector<int> uniq_cookie;
    for (auto kv : ckcount) {
      uniq_cookie.push_back(kv.first);
    }
    sort(uniq_cookie.begin(), uniq_cookie.end());

    int ret = 0;
    for (auto kid : g) {
      if (ckcount[kid]) {
        ret++;
        --ckcount[kid];
        continue;
      }
      for (auto uk : uniq_cookie) {
        if (uk < kid || ckcount[uk] == 0) {
          continue;
        }
        // the first met
        ret++;
        --ckcount[uk];
        break;
      }
    }
    return ret;
  }
};
