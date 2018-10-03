// http://leetcode.com/problems/permutation-sequence/description/
#include "one.h"

class Solution {
public:
  string getPermutation(int n, int k) {
    vector<int> digit_vec;
    int bucket_size = 1;
    for (int i = 1; i <= n; i++) {
      digit_vec.push_back(i);
      bucket_size *= i;
    }

    k--;
    string ret;
    while (!digit_vec.empty()) {
      k %= bucket_size;
      bucket_size /= digit_vec.size();
      ret.push_back(digit_vec[k / bucket_size] + '0');
      digit_vec.erase(digit_vec.begin() + (k / bucket_size));
      digit_vec.shrink_to_fit();
    }

    return ret;
  }
};
