// https://leetcode.com/problems/kth-smallest-product-of-two-sorted-arrays/
#include "xxx.hpp"

// for you to understand this question
class SolutionTTL {
public:
  long long kthSmallestProduct(vector<int> &nums1, vector<int> &nums2,
                               long long k) {
    using ll = long long;
    // prev count before val
    auto check = [&](double val) {
      long long cnt = 0;
      for (auto &x : nums1) {
        if (x < 0) {
          cnt += nums2.end() -
                 lower_bound(nums2.begin(), nums2.end(), ceil(val / x));
        } else if (x == 0) {
          if (val >= 0) {
            cnt += nums2.size();
          }
        } else {
          cnt += upper_bound(nums2.begin(), nums2.end(), floor(val / x)) -
                 nums2.begin();
        }
      }

      return cnt;
    };
    ll lo = -pow(10ll, 10);
    ll hi = pow(10ll, 10) + 1;
    while (lo < hi) {
      ll mid = lo + (hi - lo) / 2;
      if (check(mid) < k) {
        lo = mid + 1;
      } else {
        hi = mid;
      }
    }
    return lo;
  }
};

class Solution {
  using ll = long long;

public:
  long long kthSmallestProduct(vector<int> &nums1, vector<int> &nums2,
                               long long k) {
    auto zit1 = lower_bound(nums1.begin(), nums1.end(), 0);
    auto zit2 = lower_bound(nums2.begin(), nums2.end(), 0);
    vector<int> neg1(nums1.begin(), zit1);
    vector<int> neg2(nums2.begin(), zit2);
    vector<int> pos1(zit1, nums1.end());
    vector<int> pos2(zit2, nums2.end());

    vector<int> neg1_rev(rbegin(neg1), rend(neg1));
    vector<int> neg2_rev(rbegin(neg2), rend(neg2));
    vector<int> pos1_rev(rbegin(pos1), rend(pos1));
    vector<int> pos2_rev(rbegin(pos2), rend(pos2));

    ll lo = -pow(10ll, 10);
    ll hi = pow(10ll, 10);
    while (lo < hi) {
      // binary search target value
      ll m = (lo + hi - 1) / 2;
      ll cnt = 0;
      if (m >= 0) {
        // 1. all negtive(neg1 * pos2 + neg2 * pos1)
        // 2. the smaller one
        cnt = count(neg1_rev, neg2_rev, m) + count(pos1, pos2, m) +
              neg1.size() * pos2.size() + neg2.size() * pos1.size();
      } else {
        // pos * pos and neg * neg are all bigger than m
        // we just count the negative one
        cnt = count(pos2_rev, neg1, m) + count(pos1_rev, neg2, m);
      }

      if (cnt < k) {
        lo = m + 1;
      } else {
        hi = m;
      }
    }

    return lo;
  }

private:
  ll count(vector<int> &nums1, vector<int> &nums2, ll target) {
    ll cnt = 0;
    for (int p1 = 0, p2 = nums2.size() - 1; p1 < nums1.size(); ++p1) {
      while (p2 >= 0 && (long long)nums1[p1] * nums2[p2] > target) {
        --p2;
      }
      cnt += p2 + 1;
    }

    return cnt;
  }
};
