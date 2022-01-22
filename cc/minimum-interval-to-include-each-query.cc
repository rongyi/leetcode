// http://leetcode.com/problems/minimum-interval-to-include-each-query/description/
#include "xxx.hpp"

class Solution {
public:
  // 其实还是sort，集合有序，查询有序
  // 从小的点开始查询,这样可以沿着查询一直添加，弹出去的也是确定后面肯定用不着的
  vector<int> minInterval(vector<vector<int>> &intervals,
                          vector<int> &queries) {
    int sz = queries.size();
    vector<int> ret(sz, -1);
    vector<pair<int, int>> qwithidx;
    for (int i = 0; i < sz; ++i) {
      qwithidx.push_back({queries[i], i});
    }
    sort(qwithidx.begin(), qwithidx.end(),
         [](auto &l, auto &r) { return l.first < r.first; });

    // intervalrange, end]
    set<pair<int, int>> range;
    // also sort input
    sort(intervals.begin(), intervals.end());
    int i = 0;
    for (auto &q : qwithidx) {
      auto qnum = q.first;
      auto idx = q.second;
      for (; i < intervals.size() && intervals[i][0] <= qnum; i++) {
        range.insert({intervals[i][1] - intervals[i][0] + 1, intervals[i][1]});
      }
      while (range.size() && begin(range)->second < qnum) {
        range.erase(range.begin());
      }
      if (range.size()) {
        ret[idx] = range.begin()->first;
      }
    }

    return ret;
  }
};

int main() {
  vector<int> input(3, 0);
  iota(input.begin(), input.end(), 0);
  for (int i = 0; i < input.size(); ++i) {
    cout << input[i] << endl;
  }
}
