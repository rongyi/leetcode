// http://leetcode.com/problems/fruit-into-baskets/description/
#include "xxx.hpp"
#include <unordered_map>

class Solution {
public:
  int totalFruit(vector<int> &tree) {
    // sliding window prombels
    unordered_map<int, int> cnt;
    int i = 0;
    int ret = 0;
    for (int j = 0; j < tree.size(); j++) {
      cnt[tree[j]] += 1;
      while (cnt.size() > 2) {
        cnt[tree[i]] -= 1;
        if (cnt[tree[i]] == 0) {
          cnt.erase(tree[i]);
        }
        i += 1;
      }
      ret = max(ret, j - i + 1);
    }
    return ret;
  }
};
