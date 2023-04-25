// http://leetcode.com/problems/leetcode/ugly-number-ii/description/
#include "xxx.hpp"

class Solution {
public:
  int nthUglyNumber(int n) {
    priority_queue<long long, vector<long long>, greater<long long>> q;
    q.push(1);
    set<long long> visited;
    vector<long long> mul{2, 3, 5};
    while (!q.empty() && n) {
      auto cur = q.top();
      q.pop();
      n--;
      if (n == 0) {
        return cur;
      }
      for (auto m : mul) {
        long long candi = cur * m;
        if (!visited.count(candi)) {
          visited.insert(candi);
          q.push(candi);
        }
      }
    }

    return -1;
  }
};
