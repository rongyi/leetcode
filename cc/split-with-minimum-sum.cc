// https://leetcode.com/problems/split-with-minimum-sum/
#include "xxx.hpp"

class Solution {
public:
  int splitNum(int num) {
    vector<int> ds;
    while (num) {
      ds.push_back(num % 10);
      num /= 10;
    }
    sort(ds.begin(), ds.end());
    int n1 = 0;
    int n2 = 0;
    for (int i = 0; i < ds.size(); i += 2) {
      n1 = n1 * 10 + ds[i];
    }
    for (int i = 1; i < ds.size(); i += 2) {
      n2 = n2 * 10 + ds[i];
    }

    return n1 + n2;
  }
};
