// https://leetcode.com/problems/prime-subtraction-operation/
#include "xxx.hpp"

class Solution {
public:
  bool primeSubOperation(vector<int> &nums) {
    vector<int> ps = primes();

    int sz = nums.size();
    int next = nums[sz - 1];
    for (int i = sz - 2; i >= 0; i--) {
      if (nums[i] < next) {
        next = nums[i];
        continue;
      }
      bool valid = false;

      // else try to substrace prime from smaller one
      for (int pi = 0; pi < ps.size() && ps[pi] < nums[i]; pi++) {
        if (nums[i] - ps[pi] < next) {
          valid = true;
          next = nums[i] - ps[pi];
          // this the biggest next we can get, dont check
          // smaller one
          break;
        }
      }

      if (!valid) {
        return false;
      }
    }

    return true;
  }

private:
  // primes less than 1001
  vector<int> primes() {
    vector<int> p(1001, true);
    p[0] = false;
    p[1] = false;

    for (int i = 2; i * i < 1001; i++) {
      for (int j = 2 * i; j < 1001; j += i) {
        p[j] = false;
      }
    }
    vector<int> ret;
    for (int i = 0; i < 1001; i++) {
      if (p[i]) {
        ret.push_back(i);
      }
    }
    return ret;
  }
};
