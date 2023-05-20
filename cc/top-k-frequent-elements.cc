// http://leetcode.com/problems/top-k-frequent-elements/description/
#include "xxx.hpp"

class Solution {
public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    map<int, int> cnt;
    for (auto &num : nums) {
      cnt[num]++;
    }
    // {freq, num}
    priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>>
        pq;
    for (auto &kv : cnt) {
      pq.push({kv.second, kv.first});
    }
    vector<int> ret;
    while (!pq.empty() && k--) {
      auto cur = pq.top();
      pq.pop();
      ret.push_back(cur.second);
    }

    return ret;
  }
};
