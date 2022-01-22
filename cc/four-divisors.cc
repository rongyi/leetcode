// http://leetcode.com/problems/four-divisors/description/
#include "xxx.hpp"

class Solution {
public:
  int sumFourDivisors(vector<int> &nums) {
    auto ret = 0;
    for (auto &n : nums) {
      ret += hasFourDivisor(n);
    }

    return ret;
  }

private:
  int hasFourDivisor(const int &n) {
    int count = 0;
    int sum = 0;
    for (int i = 1; i * i <= n; ++i) {
      // found one
      if (n % i == 0) {
        // when i * i = n; make sure count is 1
        if (n / i == i) {
          ++count;
          sum += i;
        } else {
          count += 2;
          sum += i + n / i;
        }
      }
    }
    // not found another pair
    if (count == 4) {
      return sum;
    }

    return 0;
  }
};

int main() {
  Solution so;
  vector<int> input{21, 4, 7};
  auto ret = so.sumFourDivisors(input);
  cout << ret << endl;
}
