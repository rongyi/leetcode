// http://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/description/
#include "xxx.hpp"

class Solution {
public:
  int countTriplets(vector<int> &arr) {
    int ret = 0;
    vector<int> prefix(arr.size() + 1, 0);
    for (int i = 0; i < arr.size(); ++i) {
      prefix[i + 1] = prefix[i] ^ arr[i];
    }
    for (int i = 0; i < prefix.size(); ++i) {
      for (int j = i + 1; j < prefix.size(); ++j) {
        if (prefix[i] == prefix[j]) {
          ret += j - i - 1;
        }
      }
    }

    return ret;
  }
};
