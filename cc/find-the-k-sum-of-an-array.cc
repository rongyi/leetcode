// https://leetcode.com/problems/find-the-k-sum-of-an-array/
#include "xxx.hpp"

class Solution {
public:
  // https://leetcode.com/problems/find-the-k-sum-of-an-array/discuss/2457384/Priority-Queue-oror-C%2B%2B
  long long kSum(vector<int> &nums, int k) {
    int sz = nums.size();
    long long sum = 0;
    // the element we can substract from sum
    vector<long long> subs;
    for (int i = 0; i < sz; ++i) {
      if (nums[i] >= 0) {
        sum += nums[i];
      } else {
        // why? because add negative is same as
        // substract postive
        // so we normalize negative as postive
        // and only use substract action
        nums[i] = abs(nums[i]);
      }
    }
    sort(nums.begin(), nums.end());
    priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                   greater<pair<long long, int>>>
        pq;
    pq.push({nums[0], 0});

    while (!pq.empty() && subs.size() < k - 1) {
      auto [cursub, idx] = pq.top();
      pq.pop();

      subs.push_back(cursub);
      if (idx < sz - 1) {
        pq.push({cursub + nums[idx + 1], idx + 1});
        pq.push({nums[idx + 1] + (cursub - nums[idx]), idx + 1});
      }
    }

    vector<long long> ret;
    ret.push_back(sum);
    for (auto &cur : subs) {
      ret.push_back(sum - cur);
    }

    return ret[k - 1];
  }
};
