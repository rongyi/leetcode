// http://leetcode.com/problems/minimum-absolute-sum-difference/description/
#include "xxx.hpp"

class Solution {
public:
  // 考察的lower_bound
  int minAbsoluteSumDiff(vector<int> &nums1, vector<int> &nums2) {
    set<int> s(nums1.begin(), nums1.end());

    long ret = 0;
    long gain = 0;
    for (int i = 0; i < nums1.size(); ++i) {
      long cur_diff = abs(nums1[i] - nums2[i]);
      ret += cur_diff;
      if (gain < cur_diff) {
        auto it = s.lower_bound(nums2[i]);
        if (it != s.end()) {
          gain = max(gain, cur_diff - abs(*it - nums2[i]));
        }
        if (it != s.begin()) {
          gain = max(gain, cur_diff - abs(*prev(it) - nums2[i]));
        }
      }
    }
    return (ret - gain) % (int)(1e9 + 7);
  }
};

int main() {
  vector<int> input{1, 2, 2, 3, 3, 4};
  auto i = lower_bound(input.begin(), input.end(), -1);
  auto j = upper_bound(input.begin(), input.end(), 2);
  cout << *i << endl;
  cout << *j << endl;
}
