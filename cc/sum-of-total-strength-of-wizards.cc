// https://leetcode.com/problems/sum-of-total-strength-of-wizards/
#include "xxx.hpp"

class Solution {
public:
  int totalStrength(vector<int> &strength) {
    int sz = strength.size();
    long long mod = 1e9 + 7;
    vector<long long> prefix(sz + 1, 0ll);
    for (int i = 0; i < sz; ++i) {
      prefix[i + 1] = (prefix[i] + strength[i]) % mod;
    }
    // still shift one, don't be confused with sz + 2
    vector<long long> prefix_of_prefix(sz + 2, 0ll);
    for (int i = 0; i <= sz; ++i) {
      prefix_of_prefix[i + 1] = (prefix_of_prefix[i] + prefix[i]) % mod;
    }

    // first index which is smaller than pivot
    // left side < pivot
    vector<int> left(sz, -1);
    // mono stack
    vector<int> stack;
    for (int i = 0; i < sz; ++i) {
      while (!stack.empty() && strength[stack.back()] >= strength[i]) {
        // big than the current? fuck off
        stack.pop_back();
      }
      left[i] = stack.empty() ? -1 : stack.back();
      stack.push_back(i);
    }

    // right side <= pivot
    vector<int> right(sz, sz);
    stack.clear();
    for (int i = sz - 1; i >= 0; --i) {
      // if equal, this is the boundary
      while (!stack.empty() && strength[stack.back()] > strength[i]) {
        // fuck off
        stack.pop_back();
      }
      right[i] = stack.empty() ? sz : stack.back();
      stack.push_back(i);
    }
    long long ret = 0;
    for (int i = 0; i < sz; ++i) {
      // https://leetcode.com/problems/sum-of-total-strength-of-wizards/discuss/2062017/C%2B%2B-prefix-%2B-monotonic-stack-O(N)-solution-with-thought-process
      // notice the shift one
      ret += ((prefix_of_prefix[right[i] + 1] - prefix_of_prefix[i + 1]) *
                  (i - left[i]) % mod +
              mod * 2 -
              (prefix_of_prefix[i + 1] - prefix_of_prefix[left[i] + 1]) *
                  (right[i] - i) % mod) %
             mod * strength[i] % mod;
      ret %= mod;
    }

    return ret;
  }
};
