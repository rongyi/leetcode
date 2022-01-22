// http://leetcode.com/problems/count-largest-group/description/
#include "xxx.hpp"

// clang-format off
// Given an integer n. Each number from 1 to n is grouped according to the sum of its digits.

// Return how many groups have the largest size.



// Example 1:

// Input: n = 13
// Output: 4
// Explanation: There are 9 groups in total, they are grouped according sum of its digits of numbers from 1 to 13:
// [1,10], [2,11], [3,12], [4,13], [5], [6], [7], [8], [9]. There are 4 groups with largest size.
// Example 2:

// Input: n = 2
// Output: 2
// Explanation: There are 2 groups [1], [2] of size 1.
// Example 3:

// Input: n = 15
// Output: 6
// Example 4:

// Input: n = 24
// Output: 5

// clang-format on
class Solution {
public:
  int countLargestGroup(int n) {
    unordered_map<int, int> count;
    int msize = 0;
    for (int i = 1; i <= n; ++i) {
      auto sd = sumDigit(i);
      ++count[sd];
      msize = max(msize, count[sd]);
    }
    int ret = 0;

    for (auto &kv : count) {
      if (kv.second == msize) {
        ++ret;
      }
    }

    return ret;
  }

private:
  int sumDigit(int n) {
    int ret = 0;
    while (n) {
      ret += (n % 10);
      n /= 10;
    }

    return ret;
  }
};

int main() {
  Solution so;
  auto ret = so.countLargestGroup(13);
  cout << ret << endl;
}
