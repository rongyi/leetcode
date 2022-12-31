// https://leetcode.com/problems/minimum-total-cost-to-make-arrays-unequal/
#include "xxx.hpp"

class Solution {
public:
  long long minimumTotalCost(vector<int> &nums1, vector<int> &nums2) {
    int sz = nums1.size();
    long long ret = 0;
    map<int, int> freq;
    int max_freq = 0;
    int max_freq_val = 0;
    int to_swap = 0;

    for (int i = 0; i < sz; ++i) {
      if (nums1[i] == nums2[i]) {
        freq[nums1[i]]++;
        if (freq[nums1[i]] > max_freq) {
          max_freq_val = nums1[i];
        }
        max_freq = max(max_freq, freq[nums1[i]]);
        to_swap++;

        ret += i;
      }
    }

    for (int i = 0; i < sz; ++i) {
      if (max_freq > to_swap / 2 && nums1[i] != nums2[i] &&
          nums1[i] != max_freq_val && nums2[i] != max_freq_val) {
        ret += i;
        to_swap++;
      }
    }
    if (max_freq > to_swap / 2) {
      return -1;
    }

    return ret;
  }
};
