// https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/
#include "xxx.hpp"

class Solution {
public:
  vector<int> maxSubsequence(vector<int> &nums, int k) {
    if (k == nums.size()) {
      return nums;
    }
    vector<int> cp(nums.begin(), nums.end());
    vector<int> ret;
    // you think you should use priority queue, but nth_element is way better
    nth_element(cp.begin(), cp.begin() + k - 1, cp.end(), greater<int>());

    int cnt = count(begin(cp), begin(cp) + k, cp[k - 1]);
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] > cp[k - 1] || nums[i] == cp[k - 1] && --cnt >= 0) {
        ret.push_back(nums[i]);
      }
    }

    return ret;
  }
};

int main() {
  vector<int> input{7, 9, 8, 10, 1, 2, 3};
  nth_element(input.begin(), input.begin() + 3, input.end(), greater<int>());
  for (auto i : input) {
    cout << i << " ";
  }
  cout << endl;
}
