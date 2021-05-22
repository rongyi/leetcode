// http://leetcode.com/problems/find-the-most-competitive-subsequence/description/
#include "xxx.h"

class Solution {
public:
  vector<int> mostCompetitive(vector<int> &nums, int k) {
    vector<int> stack;
    // 保证有K个元素出来
    int num_delete = nums.size() - k;

    for (int i = 0; i < nums.size(); ++i) {
      // 在有机会删除的时候尽可能的让小的排在前面
      while (!stack.empty() && num_delete && stack.back() > nums[i]) {
        stack.pop_back();
        num_delete--;
      }
      stack.push_back(nums[i]);
    }

    return vector<int>(stack.begin(), stack.begin() + k);
  }
  vector<int> mostCompetitiveTLE(vector<int> &nums, int k) {

    const int n = nums.size();
    vector<int> ret;
    int min_digit = numeric_limits<int>::max();
    int start = 0;

    while (k > 0) {
      // 保证有K个元素出来
      int cur_min = numeric_limits<int>::max();

      int b = min(start, n - k);
      int e = max(n - k, start);

      for (int i = b; i <= e; ++i) {
        if (nums[i] < cur_min) {
          cur_min = nums[i];
          start = i + 1;
        }
      }

      ret.push_back(cur_min);
      k--;
    }

    return ret;
  }
};

int main() {
  Solution so;
  vector<int> input{84, 10, 71, 23, 66, 61, 62, 64, 34, 41, 80, 25, 91, 43,
                    4,  75, 65, 13, 37, 41, 46, 90, 55, 8,  85, 61, 95, 71};

  auto ret = so.mostCompetitive(input, 24);
  for (auto i : ret) {
    cout << i << " ";
  }
  cout << endl;
}
