// http://leetcode.com/problems/add-to-array-form-of-integer/description/
#include "xxx.h"

class Solution {
public:
  vector<int> addToArrayForm(vector<int> &A, int K) {
    reverse(A.begin(), A.end());
    const int m = A.size();
    int i = 0;
    int carry = 0;
    while (K) {
      int sum = K % 10 + carry;
      carry = sum / 10;

      if (i < m) {
        sum += A[i];
        A[i++] = sum % 10;
        carry = sum / 10;
      } else {
        A.push_back(sum % 10);
      }

      K /= 10;
    }

    for (; i < m; i++) {
      int sum = A[i] + carry;
      carry = sum / 10;
      A[i] = sum % 10;
      if (carry == 0) {
        break;
      }
    }
    if (carry) {
      A.push_back(carry);
    }
    reverse(A.begin(), A.end());
    return A;
  }
};

int main() {
  Solution so;
  vector<int> input{2, 7, 4};
  auto ret = so.addToArrayForm(input, 181);
  for (auto i : ret) {
    cout << i << " ";
  }
  cout << endl;
}
