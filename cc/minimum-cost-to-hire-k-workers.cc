// http://leetcode.com/problems/minimum-cost-to-hire-k-workers/description/
#include "xxx.h"

class Solution {
public:
  double mincostToHireWorkers(vector<int> &quality, vector<int> &wage, int K) {
    // 1. 得按比例最小的人来，什么意思： 意思就是你看那谁谁谁，能力那么强才拿那么点，你们
    //    都学着点。
    // 2. 比例最小的来，大家总共拿多少？ ==> 最小的那个比例 ratio * (k sum quality)
    vector<vector<double>> workers;
    for (int i = 0; i < quality.size(); i++) {
      workers.push_back({(double)wage[i] / (double)quality[i], (double)quality[i]});
    }
    sort(workers.begin(), workers.end());

    // 大顶堆默认
    priority_queue<int> pq;
    double ret = numeric_limits<double>::max();
    double qsum = 0;
    for (auto w : workers) {
      pq.push(w[1]);
      qsum += w[1];
      if (pq.size() > K) {
        qsum -= pq.top();
        pq.pop();
      }
      if (pq.size() == K) {
        ret = min(ret, qsum * w[0]);
      }
    }
    return ret;
  }
};
