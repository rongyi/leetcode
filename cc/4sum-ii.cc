// http://leetcode.com/problems/4sum-ii/description/
#include "xxx.h"

class Solution {
public:
  int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C,
                   vector<int> &D) {
    vector<int> merge1;
    for (auto i : A) {
      for (auto j : B) {
        merge1.push_back(i + j);
      }
    }

    unordered_map<int, int> merge2;
    for (auto i : C) {
      for (auto j : D) {
        merge2[i + j]++;
      }
    }
    int ret = 0;
    for (auto i : merge1) {
      ret += merge2[-i];
    }
    return ret;
  }
};
