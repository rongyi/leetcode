// http://leetcode.com/problems/subsets/description/
#include "xxx.h"

class Solution {
public:
  vector<vector<int>> subsets(vector<int> &nums) {
    const int n = nums.size();
    vector<vector<int>> ret;
    for (int i = 0; i < (1 << n); ++i) {
      vector<int> cur;
      for (int j = 0; j < n; ++j) {
        if ((i >> j) & 0x1) {
          cur.push_back(nums[j]);
        }
      }

      ret.push_back(cur);
    }
    return ret;
  }
};

int main() {
  Solution so;
  vector<int> input{1, 2, 3};
  auto ret = so.subsets(input);
  for (auto v: ret) {
    for (auto i : v) {
      cout << i << " ";
    }
    cout << endl;
  }
}
