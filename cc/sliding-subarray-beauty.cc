// https://leetcode.com/problems/sliding-subarray-beauty/
#include "xxx.hpp"

class Solution {
public:
  vector<int> getSubarrayBeauty(vector<int> &nums, int k, int x) {
    int sz = nums.size();
    vector<int> ret;
    map<int, int> cnt;
    // no fancy O(n) method
    for (int i = 0; i < sz; i++) {
      cnt[nums[i]]++;
      // a valid window formed
      if (i >= k - 1) {
        // cut window from tail
        if (i >= k) {
          cnt[nums[i - k]]--;
        }

        int cur_cnt = 0;
        for (auto &kv : cnt) {
          if (kv.first < 0) {
            cur_cnt += kv.second;
            if (cur_cnt >= x) {
              ret.push_back(kv.first);
              break;
            }
          } else {
            ret.push_back(0);
            break;
          }
        }
      }
    }

    return ret;
  }
};
