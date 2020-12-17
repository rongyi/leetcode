// http://leetcode.com/problems/minimum-numbers-of-function-calls-to-make-target-array/description/
#include "xxx.h"

class Solution {
public:
  int minOperations(vector<int> &nums) {
    // number of x2 operations = (highest set bit in binary representation)
    // because each x2 operation shifts the binary digit to left, hence highest
    // set bit will be number of x2 operations we will have to perform. By only
    // performing (highest set bit) number of operations, we reuse x2 operation
    // across all nums.

    // number of +1 operations = (number of 1s in the binary representation of
    // each number) because each 1 in binary representation is introduced by +1
    // operation.
    int odd = accumulate(nums.begin(), nums.end(), 0, [&](int acc, int i) {
      return acc + bitset<32>(i).count();
    });
    int max = *max_element(nums.begin(), nums.end());
    if (max > 0) {
      return odd + log2(max);
    }
    return odd;
  }
};

int main() {
  Solution so;
  vector<int> input{0};
  auto ret = so.minOperations(input);
  cout << ret << endl;
  cout << log2(0) << endl;
}
