// http://leetcode.com/problems/find-the-minimum-number-of-fibonacci-numbers-whose-sum-is-k/description/
#include "xxx.h"

class Solution {
public:
  int findMinFibonacciNumbers(int k) {
    vector<int> clt;
    collect(k, clt);

    return clt.size();
  }

private:
  void collect(int n, vector<int> &c) {
    if (n <= 0) {
      return;
    }
    if (n == 1) {
      c.push_back(n);
      return;
    }
    int sum = 0;
    int prev = 1;
    int cur = 1;
    while (true) {
      sum = prev + cur;
      if (sum >= n) {
        break;
      }
      prev = cur;
      cur = sum;
    }
    if (sum == n) {
      c.push_back(sum);
      return;
    }
    c.push_back(cur);
    collect(n - cur, c);
  }
};

int main() {
  Solution so;
  so.findMinFibonacciNumbers(7);
}
