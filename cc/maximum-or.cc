// https://leetcode.com/problems/maximum-or/
#include "xxx.hpp"

class Solution {
public:
  long long maximumOr(vector<int> &nums, int k) {
    int sz = nums.size();
    vector<long long> suffix(sz, 0);
    for (int i = sz - 2; i >= 0; i--) {
      suffix[i] = suffix[i + 1] | nums[i + 1];
    }
    long long leftacc = 0;

    long long ret = 0;
    for (int i = 0; i < sz; i++) {
      ret = max(ret, leftacc | (long long)nums[i] << k | suffix[i]);
      leftacc |= nums[i];
    }

    return ret;
  }
};

int main() {
  Solution so;
  vector<int> input{12, 9};
  so.maximumOr(input, 1);
}
