// https://leetcode.com/problems/take-gifts-from-the-richest-pile/
#include "xxx.hpp"

class Solution {
public:
  long long pickGifts(vector<int> &gifts, int k) {
    int sz = gifts.size();
    using pii = pair<int, int>;
    priority_queue<pii, vector<pii>, less<pii>> pq;
    for (int i = 0; i < sz; i++) {
      pq.push({gifts[i], i});
    }
    while (!pq.empty() && k--) {
      auto cur = pq.top();
      pq.pop();
      int left = sqrt(cur.first);
      gifts[cur.second] = left;
      // still need to push to pq
      pq.push({left, cur.second});
    }

    long long ret = 0;
    for (auto &g : gifts) {
      ret += g;
    }
    return ret;
  }
};
