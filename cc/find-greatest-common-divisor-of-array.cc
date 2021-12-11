// http://leetcode.com/problems/find-greatest-common-divisor-of-array/description/
#include "xxx.h"

class Solution {
public:
  int findGCD(vector<int> &nums) {
    int l = *min_element(nums.begin(), nums.end());
    int r = *max_element(nums.begin(), nums.end());

    return gcd(l, r);
  }

private:
  int gcd(int x, int y) {
    int r;

    while (y > 0) {
      r = x % y;
      x = y;
      y = r;
    }

    return x;
  }
};

int main() {
  Solution so;
}
