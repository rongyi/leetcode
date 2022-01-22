// http://leetcode.com/problems/length-of-longest-fibonacci-subsequence/description/
#include "xxx.hpp"

class Solution {
public:
  int lenLongestFibSubseq(vector<int> &A) {
    unordered_set<int> s(A.begin(), A.end());
    int ret = 0;
    for (int i = 0; i < A.size(); i++) {
      for (int j = i + 1; j < A.size(); j++) {
        int a = A[i];
        int b = A[j];
        int l = 2;
        while (s.count(a + b)) {
          int tmp = b;
          b = a + b;
          a = tmp;
          l++;
        }
        ret = max(ret, l);
      }
    }
    return ret > 2 ? ret : 0;
  }
};
