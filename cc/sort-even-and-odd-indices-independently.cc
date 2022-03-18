// https://leetcode.com/problems/sort-even-and-odd-indices-independently/
#include "xxx.hpp"

class Solution {
public:
  // they don't say nums is even or odd length
  vector<int> sortEvenOdd(vector<int> &nums) {
    int sz = nums.size();
    vector<int> odd;
    vector<int> even;
    for (int i = 0; i < sz; ++i) {
      if (i & 1) {
        odd.push_back(nums[i]);
      } else {
        even.push_back(nums[i]);
      }
    }
    sort(rbegin(odd), rend(odd));
    sort(begin(even), end(even));
    for (int i = 0; i < sz; i += 2) {
      nums[i] = even[i / 2];
      if (i + 1 < sz) {
        nums[i + 1] = odd[i / 2];
      }
    }
    return nums;
  }
};

int main(int argc, char *argv[]) {
  Solution so;
  vector<int> input{4, 1, 2, 3};
  so.sortEvenOdd(input);
  return 0;
}
