// https://leetcode.com/problems/steps-to-make-array-non-decreasing/
#include "xxx.hpp"

class Solution {
public:
  int totalSteps(vector<int> &nums) {
    int sz = nums.size();
    stack<pair<int,int>> stk;
    stk.push({nums[sz - 1], 0});
    int ret = 0;
    for (int i = sz - 2; i >= 0; --i) {
      int cnt = 0;
      while (!stk.empty() && stk.top().first < nums[i]) {
        // fuck off
        cnt = max(cnt +1, stk.top().second);
        stk.pop();
      }
      ret = max(ret, cnt);

      stk.push({nums[i], cnt});
    }
    return ret;
  }
};

class SolutionTLE {
public:
  int totalSteps(vector<int> &nums, int round = 0) {
    vector<int> next_round;
    next_round.push_back(nums[0]);
    int cur_cnt = 0;
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] < nums[i - 1]) {
        cur_cnt += 1;
      } else {
        next_round.push_back(nums[i]);
      }
    }
    // for (auto i: next_round)  {
    // cout << i << " ";
    //}
    // cout << endl;
    if (cur_cnt == 0) {
      return round;
    }

    return totalSteps(next_round, round + 1);
  }
};

int main() {
  Solution so;
  vector<int> input{5, 3, 4, 4, 7, 3, 6, 11, 8, 5, 11};
  so.totalSteps(input);
}
