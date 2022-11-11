// https://leetcode.com/problems/number-of-pairs-satisfying-inequality/
#include "xxx.hpp"

class Solution {
public:
  // https://leetcode.com/problems/number-of-pairs-satisfying-inequality/solutions/2646585/easy-merge-sort-based-solution-c/?orderBy=most_votes
  long long numberOfPairs(vector<int> &nums1, vector<int> &nums2, int diff) {
    ret_ = 0;

    int sz = nums1.size();
    vector<int> nums(sz, 0);
    for (int i = 0; i < sz; ++i) {
      nums[i] = nums1[i] - nums2[i];
    }
    mergeSort(nums, 0, sz - 1, diff);

    return ret_;
  }

private:
  void mergeSort(vector<int> &nums, int start, int end, int diff) {
    if (start == end) {
      return;
    }
    int mid = (start + end) / 2;
    mergeSort(nums, start, mid, diff);
    mergeSort(nums, mid + 1, end, diff);

    checkCount(nums, start, mid, end, diff);
  }
  void checkCount(vector<int> &nums, int start, int mid, int end, int diff) {
    int l = start;
    int r = mid + 1;
    // the i range is in [start, mid]
    // the j range is in [mid + 1, end]
    while (l <= mid && r <= end) {
      // if (nums[l]<=nums[r]+d) then all values from nums[r] to nums[end] will
      // be be having their summation with d greater than or equal to nums[l]
      if (nums[l] <= (nums[r] + diff)) {
        ret_ += (end - r + 1);
        l++;
      } else {
        r++;
      }
    }

    sort(nums.begin() + start, nums.begin() + end + 1);
  }

private:
  long long ret_;
};
