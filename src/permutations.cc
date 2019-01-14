// http://leetcode.com/problems/permutations/description/
#include "xxx.h"

class Solution {
public:
  vector<vector<int>> permute(vector<int> &nums) {
    vector<vector<int>> ret;
    if (nums.size() == 0) {
      return ret;
    }
    vector<int> cur;
    // doPermute(nums, ret, cur, 0);
    vector<bool> chosen(nums.size(), false);
    doPermute2(nums, chosen, ret, cur);

    return ret;
  }

private:

  void doPermute2(vector<int> &nums, vector<bool> &chosen, vector<vector<int>> &ret, vector<int> &cur) {
    if (cur.size() == nums.size()) {
      ret.push_back(cur);
      return;
    }
    for (int i = 0;i < nums.size(); i++) {
      if (chosen[i]) {
        continue;
      }
      chosen[i] = true;
      cur.push_back(nums[i]);
      doPermute2(nums, chosen, ret, cur);

      chosen[i] = false;
      cur.pop_back();
    }
  }
  // there's picture at this link show the process very well
  // https://stackoverflow.com/questions/7537791/understanding-recursion-to-generate-permutations
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
