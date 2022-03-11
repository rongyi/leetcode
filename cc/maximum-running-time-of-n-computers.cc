// https://leetcode.com/problems/maximum-running-time-of-n-computers/
#include "xxx.hpp"

class Solution {
public:
  long long maxRunTime(int n, vector<int> &bts) {
    long long sum = accumulate(begin(bts), end(bts), 0ll);
    priority_queue<int> q(bts.begin(), bts.end());

    // Let us take the "juiciest" battery that holds the charge for x minutes.
    // If the charge per computer sum / n (where sum is aggregated charge of all
    // batteries) is less than x, this battery can run one of the computers as
    // long as needed. So, we put this battery and one of the computers aside,
    // and find the answers for the remaining batteries, and n - 1 computers.

    // If the charge per computer is equal or greater than x, we can run the
    // remaining computers for sum / n minutes. And this is our answer!

    // This solution has a better complexity: O(n log m), where m is the number
    // of batteries. We pull up to n elements of of the heap of size m. We
    // initialize the heap in place, so the initialization is O(m).
    while (!q.empty() && q.top() > sum / n) {
      sum -= q.top();
      q.pop();
      n--;
    }

    return sum / n;
  }
};
