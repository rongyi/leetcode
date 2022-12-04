// https://leetcode.com/problems/total-cost-to-hire-k-workers/
#include "xxx.hpp"

class Solution {
public:
  long long totalCost(vector<int> &costs, int k, int candidates) {

    long long sum = 0;
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pql;
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pqr;
    int sz = costs.size();
    int i = 0;
    int j = sz - 1;
    for (; i < min(sz, candidates); ++i) {
      pql.push({costs[i], i});
    }
    for (; j >= max(candidates, sz - candidates); --j) {
      pqr.push({costs[j], j});
    }
    while (k--) {
      if (pql.size() > 0 && pqr.size() > 0) {
        auto l = pql.top();
        auto r = pqr.top();
        if (l[0] <= r[0]) {
          sum += l[0];
          pql.pop();
          if (i <= j) {
            pql.push({costs[i], i++});
          }
        } else {
          sum += r[0];
          pqr.pop();
          if (i <= j) {
            pqr.push({costs[j], j--});
          }
        }
      } else if (pql.size() > 0) {
        auto l = pql.top();
        pql.pop();
        sum += l[0];
        if (i <= j) {
          pql.push({costs[i], i++});
        }
      } else {
        auto r = pqr.top();
        pqr.pop();
        sum += r[0];
        if (i <= j) {
          pqr.push({costs[j], j--});
        }
      }
    }
    return sum;
  }
};

int main(int argc, char *argv[]) {
  Solution so;

  vector<int> input{17, 12, 10, 2, 7, 2, 11, 20, 8};
  so.totalCost(input, 3, 4);

  return 0;
}
