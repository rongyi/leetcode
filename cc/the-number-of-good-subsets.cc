// https://leetcode.com/problems/the-number-of-good-subsets/
#include "xxx.h"

class Solution {
public:
  int numberOfGoodSubsets(vector<int> &nums) {
    int mod = 1e9 + 7;
    using ll = long long;
    unordered_map<int, int> cnt;
    int one_cnt = 0;
    int ret = 0;
    int prime[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

    // sum all the possible prime combination count
    // 10 prime total under 30, and we count all the possible
    // combination count, at last, we sum all combination exception
    // 0, because we must at least choose one
    vector<ll> sum(1 << 10, 0);
    // empty prime count 1
    sum[0] = 1;
    vector<ll> cur;
    for (auto x : nums) {
      if (x % 4 == 0 || x % 9 == 0 || x % 25 == 0) {
        continue;
      }
      if (x == 1) {
        ++one_cnt;
      } else {
        ++cnt[x];
      }
    }
    for (auto kv : cnt) {
      int cur_mask = 0;
      for (int i = 0; i < 10; ++i) {
        if (kv.first % prime[i] == 0) {
          cur_mask += (1 << i);
        }
      }
      cur.assign(1 << 10, 0);
      // already booked prime mask
      // this loop means:
      // for all the possible mask, can we add this this num's
      // prime factor?
      // if we can, we logic or this mask and get the new mask count
      // by multiply this num's count
      for (int mask = 0; mask < (1 << 10); ++mask) {
        // do not collide with current num, ok, put current on
        // yes, we can add this mask to current mask
        if ((cur_mask & mask) == 0) {
          cur[mask | cur_mask] = (sum[mask] * kv.second) % mod;
        }
      }
      for (int i = 0; i < (1 << 10); ++i) {
        sum[i] = (sum[i] + cur[i]) % mod;
      }
    }
    // exclude empty set
    for (int i = 1; i < (1 << 10); ++i) {
      ret = (ret + sum[i]) % mod;
    }
    // the one case, pick one or not
    // e.g. [2] [1, 2]
    while (one_cnt--) {
      ret = (ret * 2) % mod;
    }

    return ret;
  }
};

class Solution0 {
public:
  // https://leetcode.com/problems/the-number-of-good-subsets/discuss/1451879/Exhaustive-DP-vs.-DP-on-Counts
  int numberOfGoodSubsets(vector<int> &nums) {
    int mod = 1e9 + 7;
    // wtf is 1024 ?
    // max value is 30, in this range all the prime is:
    // 2 3 5 7 11 13 17 19 23 29
    // total prime is 10, and mix them all(choose or not choose)
    // 2 ^ 10 ==> 1024
    int dp[1025] = {1};
    int cnt[31] = {};
    for (int i = 0; i < nums.size(); ++i) {
      ++cnt[nums[i]];
    }
    for (int i = 2; i <= 30; ++i) {
      if (mask_[i] > -1) {
        for (int mi = mask_[i], mj = 0; mj < 1024; ++mj) {
          if ((mi & mj) == 0) {
            dp[mi | mj] = (dp[mi | mj] + (long long)cnt[i] * dp[mj]) % mod;
          }
        }
      }
    }
    // exclude the empty set
    int ret = accumulate(begin(dp) + 1, end(dp), 0,
                         [&](int acc, int cur) { return (acc + cur) % mod; });
    while (--cnt[1] >= 0) {
      ret = (ret << 1) % mod;
    }

    return ret;
  }

private:
  // prime mask
  // 2  -> 1
  // 3  -> 2
  // 5  -> 4
  // 7  -> 8
  // 11 -> 16
  // non prime
  // 10 = 2 * 5 so mask with mask(2) | mask(5)  == 1 | 4 == 5
  //              0    1    2   3   4   5   6   7    8     9  10
  int mask_[31] = {-1, 0,   1,  2,  -1, 4,  3,  8,   -1,  -1, 5,
                   16, -1,  32, 9,  6,  -1, 64, -1,  128, -1, 10,
                   17, 256, -1, -1, 33, -1, -1, 512, 7};
};

int main() {
  Solution so;
  vector<int> input{1, 2, 3, 4};
  so.numberOfGoodSubsets(input);
}
