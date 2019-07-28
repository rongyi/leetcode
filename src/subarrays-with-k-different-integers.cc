// http://leetcode.com/problems/subarrays-with-k-different-integers/description/
#include "xxx.h"

class Solution {
public:
  int subarraysWithKDistinct(vector<int> &A, int K) {
    return atMostK(A, K) - atMostK(A, K - 1);
  }
  int atMostK(vector<int> &A, int K) {
    int i = 0;
    int ret = 0;
    unordered_map<int, int> count;
    for (int j = 0; j < A.size(); ++j) {
      if (!count[A[j]]++) {
        K--;
      }
      while (K < 0) {
        if (!--count[A[i]]) {
          K++;
        }
        i++;
      }
      ret += j - i + 1;
    }
    return ret;
  }
};

int main() {
  Solution so;
  vector<int> input{1, 2, 1, 2, 3};
  auto ret = so.atMostK(input, 2);
  cout << ret << endl;
  // ret = so.subarraysWithKDistinct(input, 2);
  // cout << ret << endl;
}
