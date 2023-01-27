// https://leetcode.com/problems/maximum-subsequence-score/
#include "xxx.hpp"

class Solution {
public:
  long long maxScore(vector<int> &nums1, vector<int> &nums2, int k) {
    int sz = nums1.size();
    vector<pair<int, int>> nums1_with_idx;
    for (int i = 0; i < sz; ++i) {
      nums1_with_idx.push_back({nums1[i], i});
    }
    // need to sum to max
    sort(rbegin(nums1_with_idx), rend(nums1_with_idx));
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    long long ret = 0;
    long long cur_sum = 0;
    for (int i = 0; i < sz; ++i) {
      auto idx = nums1_with_idx[i].second;
      cur_sum += nums1[idx];
      pq.push({nums2[idx], nums1_with_idx[i].first});
      if (pq.size() == k) {
        auto cur = pq.top();
        ret = max(ret, 1LL * cur_sum * cur.first);
        cur_sum -= cur.second;
        pq.pop();
      }
    }
    return ret;
  }
};
