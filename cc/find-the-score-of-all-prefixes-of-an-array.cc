// https://leetcode.com/problems/find-the-score-of-all-prefixes-of-an-array/
#include "xxx.hpp"

class Solution {
public:
  vector<long long> findPrefixScore(vector<int> &nums) {
    int sz = nums.size();
    vector<long long> ret(sz, 0);

    int cur_max = 0;

    for (int i = 0; i < sz; i++) {
      cur_max = max(cur_max, nums[i]);
      ret[i] = nums[i] + cur_max; // follow the conver function
    }
    for (int i = 1; i < sz; i++) {
      ret[i] += ret[i - 1];
    }

    return ret;
  }
};

int main() {
  Solution so;
  vector<int> input{2, 3, 7, 5, 10};
  so.findPrefixScore(input);
}
