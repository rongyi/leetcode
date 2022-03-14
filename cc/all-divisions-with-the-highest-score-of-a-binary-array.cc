// https://leetcode.com/problems/all-divisions-with-the-highest-score-of-a-binary-array/
#include "xxx.hpp"

class Solution {
public:
  vector<int> maxScoreIndices(vector<int> &nums) {
    int sz = nums.size();
    //     0..|  1...
    vector<int> left_zero(sz, 0);
    vector<int> right_one(sz, 0);

    int cur_zero = 0;
    int cur_one = 0;
    for (int i = 0; i < sz; ++i) {
      if (nums[i] == 0) {
        ++cur_zero;
      }
      if (nums[sz - i - 1] == 1) {
        ++cur_one;
      }
      left_zero[i] = cur_zero;
      right_one[sz - i - 1] = cur_one;
    }
    vector<int> ret;
    int max_score = 0;
    if (right_one[0] > left_zero[sz - 1]) {
      ret = {0};
      max_score = right_one[0];
    } else if (right_one[0] < left_zero[sz - 1]) {
      ret = {sz};
      max_score = left_zero[sz - 1];
    } else {
      ret = {0, sz};
      max_score = right_one[0];
    }
    for (int i = 1; i < sz; ++i) {
      // note the index
      int cur_score = left_zero[i - 1] + right_one[i];
      if (cur_score > max_score) {
        ret = {i};
        max_score = cur_score;
      } else if (cur_score == max_score) {
        ret.push_back(i);
      }
    }

    return ret;
  }
};


int main() {
  Solution so;
  vector<int> input{0, 0, 1, 0};
  so.maxScoreIndices(input);
}
