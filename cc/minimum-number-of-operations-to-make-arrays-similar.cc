// https://leetcode.com/problems/minimum-number-of-operations-to-make-arrays-similar/
#include "xxx.hpp"

class Solution {
public:
  long long makeSimilar(vector<int> &nums, vector<int> &target) {
    // split to odd, and even group
    vector<int> odd_nums;
    vector<int> even_nums;
    vector<int> odd_target;
    vector<int> even_target;

    sort(nums.begin(), nums.end());
    sort(target.begin(), target.end());
    for (auto &num : nums) {
      if (num & 1) {
        odd_nums.push_back(num);
      } else {
        even_nums.push_back(num);
      }
    }
    for (auto &num : target) {
      if (num & 1) {
        odd_target.push_back(num);
      } else {
        even_target.push_back(num);
      }
    }
    auto cnt = [](vector<int> &l, vector<int> &r) {
      long long ret = 0;
      for (int i = 0; i < l.size(); ++i) {
        if (l[i] > r[i]) {
          ret += (l[i] - r[i]) / 2;
        }
      }
      return ret;
    };

    return cnt(odd_nums, odd_target) + cnt(even_nums, even_target);
  }
};
