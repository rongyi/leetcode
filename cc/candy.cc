// http://leetcode.com/problems/candy/description/
#include "xxx.hpp"

class Solution {
public:
  int candy(vector<int> &ratings) {
    int sz = ratings.size();
    vector<int> dist(sz, 1);

    for (int i = 1; i < sz; i++) {
      if (ratings[i] > ratings[i - 1]) {
        dist[i] = dist[i - 1] + 1;
      }
    }
    for (int i = sz - 2; i >= 0; i--) {
      if (ratings[i] > ratings[i + 1]) {
        dist[i] = max(dist[i + 1] + 1, dist[i]);
      }
    }

    return accumulate(dist.begin(), dist.end(), 0);
  }
};
