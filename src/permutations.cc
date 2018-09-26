// http://leetcode.com/problems/permutations/description/
#include "one.h"

class Solution {
public:
  vector<vector<int>> permute(vector<int> &nums) {
    vector<vector<int>> ret;
    if (nums.size() == 0) {
      return ret;
    }
    vector<int> cur;
    doPermute(nums, ret, cur, 0);

    return ret;
  }

private:
  void doPermute(vector<int> &nums, vector<vector<int>> &ret, vector<int> &cur,
                 unsigned index) {
    if (index == nums.size()) {
      ret.push_back(cur);
      return;
    }
    for (unsigned i = index; i < nums.size(); ++i) {
      swap(nums[index], nums[i]);
      cur.push_back(nums[index]);
      doPermute(nums, ret, cur, index + 1);
      cur.pop_back();
      swap(nums[index], nums[i]);
    }
  }
};

int main() {
  Solution so;
  vector<int> input{1, 2, 3};
  auto ret = so.permute(input);
  for (auto v : ret) {
    for (auto i : v) {
      cout << i << " ";
    }
    cout << endl;
  }
}
