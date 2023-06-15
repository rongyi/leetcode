// https://leetcode.com/problems/find-score-of-an-array-after-marking-all-elements/
#include "xxx.hpp"

class Solution {
public:
  long long findScore(vector<int> &nums) {
    long long score = 0;
    using pii = pair<int, int>;
    // using priority_queue to eliminate those
    // problems
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    int sz = nums.size();
    for (int i = 0; i < sz; i++) {
      // value with index
      pq.push({nums[i], i});
    }
    set<int> marked;
    while (!pq.empty()) {
      auto [val, idx] = pq.top();
      pq.pop();
      if (marked.count(idx)) {
        continue;
      }
      marked.insert(idx);
      if (idx < sz - 1) {
        marked.insert(idx + 1);
      }
      if (idx > 0) {
        marked.insert(idx - 1);
      }
      score += val;
    }

    return score;
  }
};
