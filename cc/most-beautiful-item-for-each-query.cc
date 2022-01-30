// https://leetcode.com/problems/most-beautiful-item-for-each-query/
#include "xxx.hpp"

class Solution {
public:
  // items {{price, beauty}}
  vector<int> maximumBeauty(vector<vector<int>> &items, vector<int> &queries) {
    vector<int> ret;
    // by price
    sort(items.begin(), items.end());
    map<int, int> prefix;
    int cur_max = 0;
    for (auto &item : items) {
      // take beauty
      cur_max = max(cur_max, item[1]);
      prefix[item[0]] = cur_max;
    }
    for (auto q: queries) {
      auto it = prefix.upper_bound(q);
      if (it != prefix.begin()) {
        it = prev(it);
        ret.push_back(it->second);
      } else {
        ret.push_back(0);
      }
    }

    return ret;
  }
};
