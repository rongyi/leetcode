// http://leetcode.com/problems/minimum-cost-to-hire-k-workers/description/
#include "xxx.hpp"

// There are n workers. You are given two integer arrays quality and wage where
// quality[i] is the quality of the ith worker and wage[i] is the minimum wage
// expectation for the ith worker.

// We want to hire exactly k workers to form a paid group. To hire a group of k
// workers, we must pay them according to the following rules:

// Every worker in the paid group must be paid at least their minimum wage
// expectation. In the group, each worker's pay must be directly proportional to
// their quality. This means if a worker’s quality is double that of another
// worker in the group, then they must be paid twice as much as the other
// worker. Given the integer k, return the least amount of money needed to form
// a paid group satisfying the above conditions. Answers within 10-5 of the
// actual answer will be accepted.

class Solution {
public:
  double mincostToHireWorkers(vector<int> &quality, vector<int> &wage, int K) {
    // 1. 得按比例最小的人来，什么意思：
    // 意思就是你看那谁谁谁，能力那么强才拿那么点，你们
    //    都学着点。
    // 2. 比例最小的来，大家总共拿多少？ ==> 最小的那个比例 ratio * (k sum
    // quality)
    vector<vector<double>> workers;
    for (int i = 0; i < quality.size(); i++) {
      workers.push_back(
          {(double)wage[i] / (double)quality[i], (double)quality[i]});
    }
    sort(workers.begin(), workers.end());

    // 大顶堆默认
    priority_queue<int> pq;
    double ret = numeric_limits<double>::max();
    double qsum = 0;
    for (auto w : workers) {
      pq.push(w[1]);
      qsum += w[1];
      // Anyone who has this question:
      // Why do we choose the highest quality person to remove? Why not choosing
      // other workers? Answer: Since the workers are sorted in the increasing
      // order of the wage/quality ratio, the global ratio will never decrease.
      // For the previously scanned wrokers, we do not care about their personal
      // ratios any more because their personal ratios will always be less than
      // (or equal to) the current global ratio. So the previous workers'
      // personal ratio will never affect the total payment. Similarly, their
      // personal base payment (i.e. the wage input) has been satisfied already.
      // As the global ratio increases, their actual payemnt will only increase
      // or stay the same, and will never become lower than their base payment.
      // So when deciding whom to remove, the only thing that matters is the
      // workers' quality. With a given global ratio, removing the highest
      // quality worker will reduces the total payment as much as possible. That
      // is why we want to removing the highest quality worker.
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
