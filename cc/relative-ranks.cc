// http://leetcode.com/problems/relative-ranks/description/
#include "xxx.h"

struct mycompare {
  bool operator()(pair<int, int> &p1, pair<int, int> &p2) {
    return p1.second < p2.second;
  }
};

class Solution {
public:
  // All the scores of athletes are guaranteed to be unique.
  // 没有并列第一这一说
  vector<string> findRelativeRanks(vector<int> &nums) {
    vector<string> ret(nums.size(), "");
    priority_queue<pair<int, int>, vector<pair<int, int>>, mycompare> pq;

    for (int i = 0; i < nums.size(); i++) {
      pq.push({i, nums[i]});
    }

    int rank = 0;
    while (!pq.empty()) {
      auto p = pq.top();
      pq.pop();
      // cout << p.second << endl;
      if (rank == 0) {
        ret[p.first] = "Gold Medal";
      } else if (rank == 1) {
        ret[p.first] = "Silver Medal";
      } else if (rank == 2) {
        ret[p.first] = "Bronze Medal";
      } else {
        ret[p.first] = to_string(rank + 1);
      }
      rank++;
    }

    return ret;
  }
};
