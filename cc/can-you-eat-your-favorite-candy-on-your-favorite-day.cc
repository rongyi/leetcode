// http://leetcode.com/problems/can-you-eat-your-favorite-candy-on-your-favorite-day/description/
#include "xxx.h"

class Solution {
public:
  vector<bool> canEat(vector<int> &candiesCount, vector<vector<int>> &queries) {
    const int n = candiesCount.size();
    vector<long long> prefix(n + 1);
    for (int i = 0; i < n; ++i) {
      prefix[i + 1] = prefix[i] + candiesCount[i];
    }
    vector<bool> ret;
    for (int i = 0; i < queries.size(); ++i) {
      long long c = queries[i][0];
      long long d = queries[i][1];
      long long m = queries[i][2];
      long long lo = prefix[c] + 1;
      long long hi = prefix[c + 1];

      // 一顿狂吃(每天按最大的吃)要能追的上
      // 或者一天一颗要够吃的
      ret.push_back((lo <= (d + 1) * m) && (hi >= d + 1));
    }

    return ret;
  }
};
