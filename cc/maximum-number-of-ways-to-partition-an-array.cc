// https://leetcode.com/problems/maximum-number-of-ways-to-partition-an-array/
#include "xxx.hpp"

class Solution {
public:
  // partition to two chunks with same same
  // and can s/nums[i]/k/
  int waysToPartition(vector<int> &nums, int k) {
    using ll = long long;
    int sz = nums.size();
    vector<ll> prefix(sz, 0);
    vector<ll> suffix(sz, 0);

    prefix[0] = nums[0];
    suffix[sz - 1] = nums[sz - 1];

    for (int i = 1; i < sz; ++i) {
      prefix[i] = prefix[i - 1] + nums[i];
      suffix[sz - i - 1] = suffix[sz - i /* - 1 + 1*/] + nums[sz - i - 1];
    }
    // equal case:
    // prefix[i] == suffix[i + 1] => i + 1 is the pivot
    // |  |  |  |  |  |
    //         i
    // if we change nums[i] to k, we get d = k - nums[i];
    // so all prefix i and after will get all add diff d
    // all suffix[0..i] will all add diff d
    // left and right save the diff  count in the left
    // or right side of pivot
    unordered_map<ll, ll> left;
    unordered_map<ll, ll> right;
    // we start from left, so initially
    // all diff exist in right side
    for (int i = 0; i < sz - 1; ++i) {
      ++right[prefix[i] - suffix[i + 1]];
    }
    // equal case, without modify any num
    ll ret = right[0];

    // try to modify each nums[i] to k
    for (int i = 0; i < sz; ++i) {
      ll cur = 0;
      ll diff = k - nums[i];
      if (left.count(diff)) {
        cur += left[diff];
      }
      if (right.count(-diff)) {
        cur += right[-diff];
      }
      ret = max(ret, cur);

      // move from right side to left side
      if (i < sz - 1) {
        ll dd = prefix[i] - suffix[i + 1];
        left[dd]++;
        right[dd]--;
        if (right[dd] == 0) {
          right.erase(dd);
        }
      }
    }

    return ret;
  }
};
