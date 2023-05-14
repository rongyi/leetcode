// http://leetcode.com/problems/super-ugly-number/description/
#include "xxx.hpp"

class Solution {
public:
  int nthSuperUglyNumber(int n, vector<int> &primes) {
    priority_queue<long long, vector<long long>, greater<long long>> pq;

    pq.push(1);
    int ret = 0;
    int cnt = 0;
    while (!pq.empty() && cnt < n) {
      auto cur = pq.top();
      pq.pop();
      ret = cur;

      // the index is so confusing
      for (auto &p : primes) {
        pq.push((long long)p * cur);
      }
      while (!pq.empty() && pq.top() == cur) {
        pq.pop();
      }

      cnt++;
    }

    return ret;
  }
};

class Solution2 {
public:
  int nthSuperUglyNumber(int n, vector<int> &primes) {
    using P = pair<long long, int>;
    vector<int> index(primes.size(), 0);
    vector<long long> nums;
    nums.push_back(1);

    priority_queue<P, vector<P>, greater<P>>
        pq; // remember pair(the ugly number, who generated this ugly)
    for (int i = 0; i < primes.size(); i++)
      pq.emplace(primes[i], i); // initial ugly = prime  * 1

    while (nums.size() < n) {
      auto [value, id] = pq.top(); // get the smallest ugly
      pq.pop();

      if (value != nums.back()) {
        nums.push_back(value);
      }

      index[id]++; // the prime generated this small ugly number should move
                   // forward to multiply next ugly number
      int debug = nums[index[id]];
      pq.emplace(nums[index[id]] * primes[id], id); // push the new ugly number to pq to participate sorting
    }

    return nums.back();
  }
};

int main() {
  Solution2 so;
  vector<int> input{2, 7};
  so.nthSuperUglyNumber(10, input);
}
