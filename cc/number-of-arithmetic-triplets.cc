// https://leetcode.com/problems/number-of-arithmetic-triplets/
#include "xxx.hpp"

class Solution {
public:
  int arithmeticTriplets(vector<int> &nums, int diff) {
    map<int, bool> cnt;
    for (auto &num : nums) {
      cnt[num] = true;
    }
    int ret = 0;
    for (auto &num : nums) {
      if (cnt[num + diff] && cnt[num + 2 * diff]) {
        ret++;
      }
    }
    return ret;
  }
};

int main(int argc, char *argv[]) {
  Solution so;
  vector<int> input{0, 1, 4, 6, 7, 10};
  so.arithmeticTriplets(input, 3);
  return 0;
}
