// https://leetcode.com/problems/most-frequent-even-element/
#include "xxx.hpp"

class Solution {
public:
  int mostFrequentEven(vector<int> &nums) {
    map<int, int> cnt;
    for (auto &num : nums) {
      if ((num & 1) == 0) {
        cnt[num]++;
      }
    }
    int max_cnt = 0;
    int max_num = -1;
    for (auto &kv : cnt) {
      if (kv.second > max_cnt) {
        max_num = kv.first;
        max_cnt = kv.second;
      }
    }

    return max_num;
  }
};
