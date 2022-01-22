// http://leetcode.com/problems/binary-prefix-divisible-by-5/description/
#include "xxx.hpp"

class Solution {
public:
  vector<bool> prefixesDivBy5(vector<int> &A) {
    int prefix = 0;
    vector<bool> ret;
    for (int i = 0; i < A.size(); i++) {
      prefix <<= 1;

      prefix |= A[i];
      if (prefix % 5 == 0) {
        ret.push_back(true);
      } else {
        ret.push_back(false);
      }
      prefix %= 5;
    }
    return ret;
  }
};

int main() {
  Solution so;
  vector<int> input{0, 1, 1, 1, 1, 1};
  so.prefixesDivBy5(input);
}
