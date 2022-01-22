// http://leetcode.com/problems/minimum-xor-sum-of-two-arrays/description/
#include "xxx.hpp"

class Solution {
public:
  Solution() { memset(dp_, numeric_limits<int>::max(), sizeof(dp_)); }
  int minimumXORSum(vector<int> &nums1, vector<int> &nums2,
                    int i = 0 /* current nums1 index*/, int mask = 0) {
    if (i >= nums1.size()) {
      return 0;
    }

    if (dp_[mask] == numeric_limits<int>::max()) {
      for (int j = 0; j < nums2.size(); ++j) {
        // not yet used
        if ((mask & (1 << j)) == 0) {
          dp_[mask] = min(dp_[mask], (nums1[i] ^ nums2[j]) +
                                         minimumXORSum(nums1, nums2, i + 1,
                                                       mask | (1 << j)));
        }
      }
    }

    return dp_[mask];
  }

private:
  int dp_[16384] = {[0 ... 16383] = INT_MAX};
};

int main() {
  int nums[3] = {[0 ... 1] = 99};
  for (auto n : nums) {
    cout << n << endl;
  }
  cout << sizeof(nums) << endl;
}
