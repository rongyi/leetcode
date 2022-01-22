// http://leetcode.com/problems/smallest-range/description/
#include "xxx.hpp"

class Solution {
public:
  // https://leetcode.com/problems/smallest-range/discuss/104886/Clean-C%2B%2B-priority_queue-solution-using-iterators
  vector<int> smallestRange(vector<vector<int>> &nums) {
    using vi = vector<int>::iterator;
    using pvi = pair<vi, vi>;
    struct cmp {
      bool operator()(pvi p1, pvi p2) {
        return *p1.first > *p2.first;
      }
    };
    int lo = numeric_limits<int>::max();
    int hi = numeric_limits<int>::min();
    priority_queue<pvi, vector<pvi>, cmp> pq;

    for (auto &row : nums) {
      lo = min(lo, row[0]);
      hi = max(hi, row[0]);
      pq.push({row.begin(), row.end()});
    }
    vector<int> ret = {lo, hi};
    while (true) {
      // 一组里面最小的
      auto p = pq.top();
      pq.pop();
      ++p.first;
      if (p.first == p.second) {
        break;
      }
      pq.push(p);

      lo = *pq.top().first;
      hi = max(hi, *p.first);
      if (hi - lo < ret[1] - ret[0]) {
        ret = {lo, hi};
      }
    }
    return ret;
  }
};
