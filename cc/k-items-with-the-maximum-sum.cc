// https://leetcode.com/problems/k-items-with-the-maximum-sum/
#include "xxx.hpp"

class Solution {
public:
  int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
    // pick ballone first
    if (numOnes >= k) {
      return k;
    }

    int pick = numOnes;
    k -= numOnes;
    k -= numZeros;
    // we have to take neg ball
    if (k > 0) {
      pick -= k;
    }
    return pick;
  }
};
