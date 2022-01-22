// http://leetcode.com/problems/minimum-increment-to-make-array-unique/description/
#include "xxx.hpp"

class Solution {
public:
  int minIncrementForUnique(vector<int> &A) {
    sort(A.begin(), A.end());
    int ret = 0;
    // already sorted
    for (int i = 1; i < A.size(); i++) {
      if (A[i] <= A[i - 1]) {
        ret += A[i - 1] + 1 - A[i];
        A[i] = A[i - 1] + 1;
      }
    }
    return ret;
  }
};

int main() {
  Solution so;
  vector<int> input{7, 2, 7, 2, 1, 4, 3, 1, 4, 8};
  auto ret = so.minIncrementForUnique(input);
  cout << ret << endl;
}
