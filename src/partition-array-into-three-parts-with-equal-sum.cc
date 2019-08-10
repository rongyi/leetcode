// http://leetcode.com/problems/partition-array-into-three-parts-with-equal-sum/description/
#include "xxx.h"

class Solution {
public:
  bool canThreePartsEqualSum(vector<int> &A) {
    int total = accumulate(A.begin(), A.end(), 0);
    if (total % 3 != 0) {
      return false;
    }
    int part = 0;
    int sum = 0;
    for (auto num : A) {
      sum += num;
      if (sum == total / 3) {
        ++part;
        sum = 0;
      }
    }
    if (total == 0) {
      return part >= 3;
    }

    return part == 3;
  }
};

int main() {
  Solution so;
  vector<int> input{1, 1, 1};
  so.canThreePartsEqualSum(input);
}
