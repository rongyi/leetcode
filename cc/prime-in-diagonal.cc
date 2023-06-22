// https://leetcode.com/problems/prime-in-diagonal/
#include "xxx.hpp"

class Solution {
public:
  int diagonalPrime(vector<vector<int>> &nums) {
    int sz = nums.size();
    int ret = 0;
    for (int i = 0; i < sz; i++) {
      if (is_prime(nums[i][i])) {
        ret = max(ret, nums[i][i]);
      }
      if (is_prime(nums[i][sz - i - 1])) {
        ret = max(ret, nums[i][sz - i - 1]);
      }
    }

    return ret;
  }

  bool is_prime(int num) {
    if (num < 2) {
      return false;
    }
    for (int i = 2; i * i <= num; i++) {
      if (num % i == 0) {
        return false;
      }
    }
    return true;
  }
};

int main() {
  Solution so;
  cout << so.is_prime(883) << endl;
  cout << so.is_prime(991) << endl;
}
