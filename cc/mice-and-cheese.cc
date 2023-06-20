// https://leetcode.com/problems/mice-and-cheese/
#include "xxx.hpp"

class Solution {
public:
  int miceAndCheese(vector<int> &reward1, vector<int> &reward2, int k) {
    int sz = reward1.size();
    int ret = 0;
    priority_queue<int> pq;
    for (int i = 0; i < sz; i++) {
      ret += reward2[i];
      pq.push(reward1[i] - reward2[i]);
    }
    while (k--) {
      ret += pq.top();
      pq.pop();
    }

    return ret;
  }
};
