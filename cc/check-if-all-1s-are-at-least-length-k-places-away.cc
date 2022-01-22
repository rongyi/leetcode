// http://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away/description/
#include "xxx.hpp"

class Solution {
public:
  bool kLengthApart(vector<int> &nums, int k) {
    int prev_one_index = -1;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] == 0) {
        continue;
      }
      if (prev_one_index == -1) {
        prev_one_index = i;
      } else {
        if (i - prev_one_index - 1 < k) {
          return false;
        }
        prev_one_index = i;
      }
    }

    return true;
  }
};

int main() {
  Solution so;
  vector<int> input{1, 0, 0, 1, 0, 1};
  auto ret = so.kLengthApart(input, 2);
  cout << ret << endl;
}
