// http://leetcode.com/problems/find-xor-sum-of-all-pairs-bitwise-and/description/
#include "xxx.hpp"

class Solution {
public:
  int getXORSum(vector<int> &arr1, vector<int> &arr2) {
    int sum1 = 0;
    //(x1 & b1) ^ (x2 & b1) ^ ... (xn & b1) ==>
    // (x1 ^ x2 ^ ... ^ xn) & b1
    for (auto num : arr1) {
      sum1 ^= num;
    }
    int ret = 0;
    for (auto num : arr2) {
      ret ^= (num & sum1);
    }
    return ret;
  }
};
