// https://leetcode.com/problems/collecting-chocolates/
#include "xxx.hpp"

class Solution {
public:
  long long minCost(vector<int> &nums, int x) {
    long long ret = numeric_limits<long long>::max();
    int sz = nums.size();
    vector<long long> collect(nums.begin(), nums.end());
    for (long long r = 0; r < sz; r++) {
      long long cur_collect = 0;
      // every shift, the smallest will affect one number
      // to be the smallest one
      // 18 10 2
      // 18 2 2   shift one
      // 2 2 2    shift again
      for (int i = 0; i < sz; i++) {
        collect[i] = min(collect[i], (long long)nums[(i + r) % sz]);
        cur_collect += collect[i];
      }
      cur_collect += r * x;
      ret = min(ret, cur_collect);
    }

    return ret;
  }
};

int main() {
  Solution so;
  vector<int> input{20, 1, 15};
  so.minCost(input, 5);
}
