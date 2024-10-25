// http://leetcode.com/problems/partition-array-into-three-parts-with-equal-sum/description/
#include "xxx.hpp"

class Solution {
public:
  bool canThreePartsEqualSum(vector<int> &A) {
    int total = accumulate(A.begin(), A.end(), 0);
    if (total % 3 != 0) {
      return false;
    }
    int part = 0;
    int sum = 0;
    for (int i = 0; i < A.size(); i+= 1) {
      sum += A[i];
      if (sum == total / 3) {
        ++part;
        sum = 0;
      }
      if (part == 2 && i != A.size() - 1) {
        return true;
      }
      
    }
    return false;
  }
};

int main() {
  Solution so;
  vector<int> input{1, 1, 1};
  so.canThreePartsEqualSum(input);
}
