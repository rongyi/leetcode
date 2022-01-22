// http://leetcode.com/problems/sum-of-all-odd-length-subarrays/description/
#include "xxx.hpp"

class Solution {
public:
  int sumOddLengthSubarrays(vector<int> &arr) {
    int ret = 0;
    vector<int> psum(arr.size() + 1, 0);
    for (int i = 0; i < arr.size(); ++i) {
      psum[i + 1] = psum[i] + arr[i];
    }
    for (int i = 0; i < arr.size(); ++i) {
      for (int j = i; j < arr.size(); ++j) {
        if ((j - i + 1) % 2 == 1) {
          ret += psum[j + 1] - psum[i];
        }
      }
    }
    return ret;
  }
};

int main() {
  Solution so;
  vector<int> input{1, 4, 2, 5, 3};
  so.sumOddLengthSubarrays(input);
}
