// https://leetcode.com/problems/smallest-rotation-with-highest-score/description/
#include "one.h"
class Solution {
public:
  // https://leetcode.com/problems/smallest-rotation-with-highest-score/discuss/118725/Easy-and-Concise-5-lines-Solution-C++JavaPython?page=1
  // 1. 要求某一位置上值 <= 当前index  ==> A[i] <= i，对于数组的取值范围： 0-数组长度，0放哪里都满足条件，
  // N放哪里都不满足条件
  int bestRotation(vector<int> &A) {
    const int n = A.size();
    vector<int> change(n, 0);
    for (int i = 0; i < n; ++i) {
      change[(i - A[i] + n + 1) % n] -= 1;
    }
    for (int i = 1; i < n; ++i) {
      change[i] += change[i - 1] + 1;
    }

    return max_element(change.begin(), change.end()) - change.begin();
  }
};

int main() {
  Solution so;
  vector<int> input{2, 3, 1, 4, 0};
  auto test = so.bestRotation(input);
  cout << test << endl;
}
