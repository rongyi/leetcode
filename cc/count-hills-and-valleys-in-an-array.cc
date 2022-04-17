// https://leetcode.com/problems/count-hills-and-valleys-in-an-array/
#include "xxx.hpp"

class Solution {
public:
  // shitty problem
  int countHillValley(vector<int> &nums) {
    vector<int> drop_same;
    for (auto &num : nums) {
      if (drop_same.empty() || drop_same.back() != num) {
        drop_same.push_back(num);
      }
    }
    nums = drop_same;

    int total_hill_vally = 0;
    int sz = nums.size();
    vector<int> prev(sz, -1);
    vector<int> after(sz, -1);
    for (int i = 1, cur_prev = nums[0], cur_prev_index = 0; i < sz; ++i) {
      if (nums[i] != cur_prev) {
        prev[i] = cur_prev;
        cur_prev_index = i;
      } else {
        prev[i] = prev[cur_prev_index];
      }
      cur_prev = nums[i];
    }

    for (int i = sz - 2, cur_after = nums[sz - 1], cur_after_index = sz - 1;
         i > 0; --i) {
      if (nums[i] != cur_after) {
        after[i] = cur_after;
        cur_after_index = i;
      } else {
        after[i] = after[cur_after_index];
      }
      cur_after = nums[i];
    }

    for (int i = 1; i < sz - 1; ++i) {
      if (prev[i] != -1 && after[i] != -1) {
        if ((prev[i] > nums[i] && after[i] > nums[i]) ||
            (prev[i] < nums[i] && after[i] < nums[i])) {
          // cout << "left" << prev[i] << " cur: " << nums[i]
          //<< " right: " << after[i] << " index: " << i << endl;
          total_hill_vally++;
        }
      }
    }

    return total_hill_vally;
  }
};

int main(int argc, char *argv[]) {
  Solution so;
  vector<int> input{6, 6, 5, 5, 4, 1};
  so.countHillValley(input);
  return 0;
}
