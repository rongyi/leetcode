// https://leetcode.com/problems/smallest-subarrays-with-maximum-bitwise-or/
#include "xxx.hpp"

class Solution {
public:
  vector<int> smallestSubarrays(vector<int> &nums) {
    int sz = nums.size();
    vector<set<int>> pos_idx(32);
    for (int i = 0; i < sz; ++i) {
      int cur = nums[i];
      for (int pos = 0; pos < 32; ++pos) {
        if ((cur >> pos) & 1) {
          pos_idx[pos].insert(i);
        }
      }
    }

    vector<int> ret(sz, 0);
    for (int i = 0; i < sz; ++i) {
      int right_most = i;
      // note the iteration
      for (int pos = 0; pos < 32; ++pos) {
        auto it = pos_idx[pos].lower_bound(i);
        if (it != pos_idx[pos].end()) {
          right_most = max(right_most, *it);
        }
      }
      // cout << right_most << endl;
      ret[i] = right_most - i + 1;
    }

    return ret;
  }
};

class SolutionTLE {
public:
  vector<int> smallestSubarraysTLE(vector<int> &nums) {
    int sz = nums.size();
    vector<int> ret(sz, 0);
    for (int i = 0; i < sz; ++i) {
      int cur = nums[i];
      int last_ch = i;
      for (int j = i + 1; j < sz; ++j) {
        int acc = cur | nums[j];
        // if we find the value is increase
        // we make this index valid
        // else this pos is useless
        // so the last change pos is
        // what we need
        if (acc != cur) {
          last_ch = j;
        }
        cur = acc;
      }
      ret[i] = last_ch - i + 1;
    }

    return ret;
  }
};

int main(int argc, char *argv[]) {
  Solution so;
  vector<int> input{1, 0, 2, 1, 3};
  so.smallestSubarrays(input);
  return 0;
}
