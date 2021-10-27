// https://leetcode.com/problems/maximum-product-difference-between-two-pairs/
#include "xxx.h"

class Solution {
public:
  int maxProductDifference(vector<int> &nums) {
    long long big = numeric_limits<int>::min();
    long long bigger = numeric_limits<int>::min();

    long long small = numeric_limits<int>::max();
    long long smaller = numeric_limits<int>::max();

    for (auto &n : nums) {
      if (n > bigger) {
        big = bigger;
        bigger = n;
      } else if (n > big) { // still need to check again
        big = n;
      }
      if (n < smaller) {
        small = smaller;
        smaller = n;
      } else if (n < small) { // still need to check again
        small = n;
      }
    }
    return (bigger * big) - (small * smaller);
  }
};

int main() {
  Solution so;
  vector<int> input{5, 6, 2, 7, 4};
  so.maxProductDifference(input);
}
