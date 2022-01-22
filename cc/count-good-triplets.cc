// http://leetcode.com/problems/count-good-triplets/description/
#include "xxx.hpp"

class Solution {
public:
  // 令人作呕，喷的很惨
  int countGoodTriplets(vector<int> &arr, int a, int b, int c) {
    int ret = 0;
    for (int i = 0; i < arr.size(); ++i) {
      for (int j = i + 1; j < arr.size(); ++j) {
        for (int k = j + 1; k < arr.size(); ++k) {
          if (abs(arr[i] - arr[j]) <= a && abs(arr[j] - arr[k]) <= b &&
              abs(arr[i] - arr[k]) <= c) {
            ++ret;
          }
        }
      }
    }

    return ret;
  }
};
